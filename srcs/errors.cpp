/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 21:05:50 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/25 16:19:45 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

TEST(errors, fd_not_opened)
{
	EXPECT_EXIT({

		const int	fd = open("assets/empty.txt", O_RDONLY);

		close(fd);

		const char	*line = get_next_line(fd);

		exit(!!line);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(errors, fd_invalid)
{
	EXPECT_EXIT({
		const int	fd = -1;

		const char	*line = get_next_line(fd);

		exit(!!line);
	}, ::testing::ExitedWithCode(0), "");
}

TEST(errors, fd_too_large)
{
	EXPECT_EXIT({
		const int	fd = INT_MAX;

		const char	*line = get_next_line(fd);

		exit(!!line);
	}, ::testing::ExitedWithCode(0), "");
}
