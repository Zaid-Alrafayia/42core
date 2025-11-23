/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:06:19 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/11/22 01:34:16 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Assuming your get_next_line prototype
char	*get_next_line(int fd);

void	test_header(const char *test_name)
{
	printf("\n========================================\n");
	printf("TEST: %s\n", test_name);
	printf("========================================\n");
}

void	test_result(const char *expected, const char *got, int line_num)
{
	if (got == NULL && expected == NULL)
		printf("Line %d: ✓ (both NULL)\n", line_num);
	else if (got == NULL)
		printf("Line %d: ✗ Expected: '%s', Got: NULL\n", line_num, expected);
	else if (expected == NULL)
		printf("Line %d: ✗ Expected: NULL, Got: '%s'\n", line_num, got);
	else if (strcmp(expected, got) == 0)
		printf("Line %d: ✓ '%s'\n", line_num, got);
	else
		printf("Line %d: ✗ Expected: '%s', Got: '%s'\n", line_num, expected,
			got);
}

// Test 1: Invalid file descriptor
void	test_invalid_fd(void)
{
	char	*line;

	test_header("Invalid File Descriptor");
	line = get_next_line(-1);
	printf("FD = -1: %s\n", line == NULL ? "NULL ✓" : "NOT NULL ✗");
	free(line);
	line = get_next_line(-42);
	printf("FD = -42: %s\n", line == NULL ? "NULL ✓" : "NOT NULL ✗");
	free(line);
	line = get_next_line(999);
	printf("FD = 999 (not open): %s\n", line == NULL ? "NULL ✓" : "NOT NULL ✗");
	free(line);
}

// Test 2: Empty file
void	test_empty_file(void)
{
	int		fd;
	char	*line;

	test_header("Empty File");
	// Create empty file
	fd = open("test_empty.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	close(fd);
	fd = open("test_empty.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Empty file: %s\n", line == NULL ? "NULL ✓" : "NOT NULL ✗");
	free(line);
	close(fd);
	unlink("test_empty.txt");
}

// Test 3: Single line without newline
void	test_single_line_no_newline(void)
{
	int		fd;
	char	*line;

	test_header("Single Line Without Newline");
	fd = open("test_no_nl.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "Hello World", 11);
	close(fd);
	fd = open("test_no_nl.txt", O_RDONLY);
	line = get_next_line(fd);
	test_result("Hello World\n", line, 1);
	free(line);
	line = get_next_line(fd);
	test_result(NULL, line, 2);
	free(line);
	close(fd);
	unlink("test_no_nl.txt");
}

// Test 4: Single line with newline
void	test_single_line_with_newline(void)
{
	int		fd;
	char	*line;

	test_header("Single Line With Newline");
	fd = open("test_with_nl.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "Hello World\n", 12);
	close(fd);
	fd = open("test_with_nl.txt", O_RDONLY);
	line = get_next_line(fd);
	test_result("Hello World\n", line, 1);
	free(line);
	line = get_next_line(fd);
	test_result(NULL, line, 2);
	free(line);
	close(fd);
	unlink("test_with_nl.txt");
}

// Test 5: Multiple lines
void	test_multiple_lines(void)
{
	int		fd;
	char	*line;

	test_header("Multiple Lines");
	fd = open("test_multi.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "Line 1\nLine 2\nLine 3\n", 21);
	close(fd);
	fd = open("test_multi.txt", O_RDONLY);
	line = get_next_line(fd);
	test_result("Line 1\n", line, 1);
	free(line);
	line = get_next_line(fd);
	test_result("Line 2\n", line, 2);
	free(line);
	line = get_next_line(fd);
	test_result("Line 3\n", line, 3);
	free(line);
	line = get_next_line(fd);
	test_result(NULL, line, 4);
	free(line);
	close(fd);
	unlink("test_multi.txt");
}

// Test 6: Only newlines
void	test_only_newlines(void)
{
	int		fd;
	char	*line;

	test_header("Only Newlines");
	fd = open("test_newlines.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "\n\n\n", 3);
	close(fd);
	fd = open("test_newlines.txt", O_RDONLY);
	line = get_next_line(fd);
	test_result("\n", line, 1);
	free(line);
	line = get_next_line(fd);
	test_result("\n", line, 2);
	free(line);
	line = get_next_line(fd);
	test_result("\n", line, 3);
	free(line);
	line = get_next_line(fd);
	test_result(NULL, line, 4);
	free(line);
	close(fd);
	unlink("test_newlines.txt");
}

// Test 7: Very long line
void	test_very_long_line(void)
{
	int		fd;
	char	*line;

	test_header("Very Long Line (10000 chars)");
	fd = open("test_long.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	for (int i = 0; i < 10000; i++)
		write(fd, "a", 1);
	write(fd, "\n", 1);
	close(fd);
	fd = open("test_long.txt", O_RDONLY);
	line = get_next_line(fd);
	if (line && strlen(line) == 10001 && line[10000] == '\n')
		printf("Long line: ✓ (length = %zu)\n", strlen(line));
	else
		printf("Long line: ✗ (length = %zu)\n", line ? strlen(line) : 0);
	free(line);
	close(fd);
	unlink("test_long.txt");
}

// Test 8: Mix of long and short lines
void	test_mixed_lengths(void)
{
	int		fd;
	char	*line;

	test_header("Mixed Line Lengths");
	fd = open("test_mixed.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "short\n", 6);
	for (int i = 0; i < 1000; i++)
		write(fd, "x", 1);
	write(fd, "\nmedium line here\n", 18);
	write(fd, "a\n", 2);
	close(fd);
	fd = open("test_mixed.txt", O_RDONLY);
	line = get_next_line(fd);
	test_result("short\n", line, 1);
	free(line);
	line = get_next_line(fd);
	printf("Line 2: %s (length = %zu)\n", (line
			&& strlen(line) == 1001) ? "✓" : "✗", line ? strlen(line) : 0);
	free(line);
	line = get_next_line(fd);
	test_result("medium line here\n", line, 3);
	free(line);
	line = get_next_line(fd);
	test_result("a\n", line, 4);
	free(line);
	close(fd);
	unlink("test_mixed.txt");
}

// Test 9: Binary content (with null bytes)
void	test_binary_content(void)
{
	int		fd;
	char	binary[] = "Hello\0World\n";
	char	*line;

	test_header("Binary Content (null bytes)");
	fd = open("test_binary.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, binary, 12);
	close(fd);
	fd = open("test_binary.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Binary content: %s\n", line ? "Got line" : "NULL");
	if (line)
		printf("First part: '%s' (might be truncated at null byte)\n", line);
	free(line);
	close(fd);
	unlink("test_binary.txt");
}

// Test 10: Reading from stdin simulation
void	test_stdin_reading(void)
{
	test_header("Reading from STDIN (fd=0)");
	printf("Note: Skipping interactive stdin test in automated mode\n");
	printf("To test manually: run program and type lines\n");
}

// Test 11: Multiple file descriptors
void	test_multiple_fds(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	test_header("Multiple File Descriptors");
	// Create two files
	fd1 = open("test_fd1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd1, "File1-Line1\nFile1-Line2\n", 24);
	close(fd1);
	fd2 = open("test_fd2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd2, "File2-Line1\nFile2-Line2\n", 24);
	close(fd2);
	// Open both for reading
	fd1 = open("test_fd1.txt", O_RDONLY);
	fd2 = open("test_fd2.txt", O_RDONLY);
	// Alternate between files
	line = get_next_line(fd1);
	test_result("File1-Line1\n", line, 1);
	free(line);
	line = get_next_line(fd2);
	test_result("File2-Line1\n", line, 1);
	free(line);
	line = get_next_line(fd1);
	test_result("File1-Line2\n", line, 2);
	free(line);
	line = get_next_line(fd2);
	test_result("File2-Line2\n", line, 2);
	free(line);
	close(fd1);
	close(fd2);
	unlink("test_fd1.txt");
	unlink("test_fd2.txt");
}

// Test 12: Closing and reopening file
void	test_close_reopen(void)
{
	int		fd;
	char	*line;

	test_header("Close and Reopen File");
	fd = open("test_reopen.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "Line 1\nLine 2\nLine 3\n", 21);
	close(fd);
	// First read
	fd = open("test_reopen.txt", O_RDONLY);
	line = get_next_line(fd);
	test_result("Line 1\n", line, 1);
	free(line);
	close(fd);
	// Reopen and read again (should start from beginning)
	fd = open("test_reopen.txt", O_RDONLY);
	line = get_next_line(fd);
	test_result("Line 1\n", line, 1);
	free(line);
	line = get_next_line(fd);
	test_result("Line 2\n", line, 2);
	free(line);
	close(fd);
	unlink("test_reopen.txt");
}

// Test 13: Line ending with EOF immediately after newline
void	test_eof_after_newline(void)
{
	int		fd;
	char	*line;

	test_header("EOF Immediately After Newline");
	fd = open("test_eof.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "Line 1\n", 7);
	close(fd);
	fd = open("test_eof.txt", O_RDONLY);
	line = get_next_line(fd);
	test_result("Line 1\n", line, 1);
	free(line);
	line = get_next_line(fd);
	test_result(NULL, line, 2);
	free(line);
	// Try reading again after EOF
	line = get_next_line(fd);
	test_result(NULL, line, 3);
	free(line);
	close(fd);
	unlink("test_eof.txt");
}

// Test 14: Special characters
void	test_special_characters(void)
{
	int		fd;
	char	*line;

	test_header("Special Characters");
	fd = open("test_special.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "Tab:\there\nQuote:\"test\"\nBackslash:\\\n", 35);
	close(fd);
	fd = open("test_special.txt", O_RDONLY);
	line = get_next_line(fd);
	test_result("Tab:\there\n", line, 1);
	free(line);
	line = get_next_line(fd);
	test_result("Quote:\"test\"\n", line, 2);
	free(line);
	line = get_next_line(fd);
	test_result("Backslash:\\\n", line, 3);
	free(line);
	close(fd);
	unlink("test_special.txt");
}

// Test 15: Memory leak check helper
void	test_memory_leaks(void)
{
	int		fd;
	char	*line;

	test_header("Memory Leak Test Helper");
	printf("Run with valgrind to check for memory leaks:\n");
	printf("valgrind --leak-check=full --show-leak-kinds=all ./test_gnl\n\n");
	fd = open("test_leaks.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, "Test\nLine\n", 10);
	close(fd);
	fd = open("test_leaks.txt", O_RDONLY);
	for (int i = 0; i < 3; i++)
	{
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	unlink("test_leaks.txt");
	printf("Completed memory leak test cycle\n");
}

int	main(void)
{
	printf("\n╔════════════════════════════════════════╗\n");
	printf("║  GET_NEXT_LINE COMPREHENSIVE TESTS    ║\n");
	printf("╚════════════════════════════════════════╝\n");
	test_invalid_fd();
	test_empty_file();
	test_single_line_no_newline();
	test_single_line_with_newline();
	test_multiple_lines();
	test_only_newlines();
	test_very_long_line();
	test_mixed_lengths();
	test_binary_content();
	test_stdin_reading();
	test_multiple_fds();
	test_close_reopen();
	test_eof_after_newline();
	test_special_characters();
	test_memory_leaks();
	printf("\n╔════════════════════════════════════════╗\n");
	printf("║         ALL TESTS COMPLETED            ║\n");
	printf("╚════════════════════════════════════════╝\n\n");
	return (0);
}
