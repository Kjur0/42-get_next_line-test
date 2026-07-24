/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 21:09:39 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/24 21:40:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(stdin, stdin)
{
	const int	fd = 0;

	char		*line1 = get_next_line(fd);
	char		*line2 = get_next_line(fd);
	char		*line3 = get_next_line(fd);
	char		*line4 = get_next_line(fd);
	char		*line5 = get_next_line(fd);

	ASSERT_NE(line1, nullptr);
	EXPECT_STREQ(line1, "\n");
	ASSERT_NE(line2, nullptr);
	EXPECT_STREQ(line2, "a\n");
	ASSERT_NE(line3, nullptr);
	EXPECT_STREQ(line3, "b\n");
	ASSERT_NE(line4, nullptr);
	EXPECT_STREQ(line4, "c\n");
	ASSERT_NE(line5, nullptr);
	EXPECT_STREQ(line5, " d\n");

	free(line1);
	free(line2);
	free(line3);
	free(line4);
	free(line5);
}
