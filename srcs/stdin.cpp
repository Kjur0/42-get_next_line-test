/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 21:09:39 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/25 16:20:09 by kjurkows         ###   ########.fr       */
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
	free(line1);

	ASSERT_NE(line2, nullptr);
	EXPECT_STREQ(line2, "a\n");
	free(line2);

	ASSERT_NE(line3, nullptr);
	EXPECT_STREQ(line3, "b\n");
	free(line3);

	ASSERT_NE(line4, nullptr);
	EXPECT_STREQ(line4, "c\n");
	free(line4);

	ASSERT_NE(line5, nullptr);
	EXPECT_STREQ(line5, " d\n");
	free(line5);
}
