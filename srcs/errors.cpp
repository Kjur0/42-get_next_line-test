/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 21:05:50 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/24 21:10:45 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

#include <fcntl.h>
#include <unistd.h>

TEST(errors, fd_not_opened)
{
	EXPECT_EXIT({

		const int	fd = open("assets/empty.txt", O_RDONLY);

		close(fd);

		const char	*line = get_next_line(fd);

		EXPECT_EQ(line, nullptr);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(errors, fd_invalid)
{
	EXPECT_EXIT({
		const int	fd = -1;

		const char	*line = get_next_line(fd);

		EXPECT_EQ(line, nullptr);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(errors, fd_too_large)
{
	EXPECT_EXIT({
		const int	fd = 10000;

		const char	*line = get_next_line(fd);

		EXPECT_EQ(line, nullptr);

		exit(0);
	}, ::testing::ExitedWithCode(0), "");
}
