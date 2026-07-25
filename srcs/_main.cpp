/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 19:02:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/25 16:20:20 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

TEST(norminette, norme)
{
	const int	exit_code = system("norminette");

	EXPECT_EQ(exit_code, 0);
}

int	main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return (RUN_ALL_TESTS());
}
