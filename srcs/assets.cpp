/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:44:37 by kjurkows          #+#    #+#             */
/*   Updated: 2026/07/25 17:56:49 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_main.hpp"

#include <fcntl.h>
#include <unistd.h>

TEST(assets, empty)
{
	const int	fd = open("assets/empty.txt", O_RDONLY);

	char		*line1 = get_next_line(fd);
	char 		*line2 = get_next_line(fd);

	ASSERT_EQ(line1, nullptr);
	EXPECT_EQ(line2, nullptr);

	close(fd);
}

TEST(assets, nl)
{
	const int	fd = open("assets/nl.txt", O_RDONLY);

	char		*line1 = get_next_line(fd);
	char		*line2 = get_next_line(fd);

	ASSERT_NE(line1, nullptr);
	EXPECT_STREQ(line1, "\n");
	free(line1);

	EXPECT_EQ(line2, nullptr);

	close(fd);
}

TEST(assets, space)
{
	const int	fd = open("assets/space.txt", O_RDONLY);

	char		*line1 = get_next_line(fd);
	char		*line2 = get_next_line(fd);

	ASSERT_NE(line1, nullptr);
	EXPECT_STREQ(line1, " ");
	free(line1);

	EXPECT_EQ(line2, nullptr);

	close(fd);
}

TEST(assets, space_nl)
{
	const int	fd = open("assets/space_nl.txt", O_RDONLY);

	char		*line1 = get_next_line(fd);
	char		*line2 = get_next_line(fd);

	ASSERT_NE(line1, nullptr);
	EXPECT_STREQ(line1, " \n");
	free(line1);

	EXPECT_EQ(line2, nullptr);

	close(fd);
}

TEST(assets, 2line)
{
	const int	fd = open("assets/2line.txt", O_RDONLY);

	char		*line1 = get_next_line(fd);
	char		*line2 = get_next_line(fd);
	char		*line3 = get_next_line(fd);

	ASSERT_NE(line1, nullptr);
	EXPECT_STREQ(line1, "a\n");
	free(line1);

	ASSERT_NE(line2, nullptr);
	EXPECT_STREQ(line2, "b\n");
	free(line2);

	EXPECT_EQ(line3, nullptr);

	close(fd);
}

TEST(assets, long_line)
{
	const int	fd = open("assets/long_line.txt", O_RDONLY);

	char		*line1 = get_next_line(fd);
	char		*line2 = get_next_line(fd);

	ASSERT_NE(line1, nullptr);
	EXPECT_STREQ(line1, "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	free(line1);

	EXPECT_EQ(line2, nullptr);

	close(fd);
}

TEST(assets, lorem)
{
	const int	fd = open("assets/lorem.txt", O_RDONLY);

	char		*line1 = get_next_line(fd);
	char		*line2 = get_next_line(fd);
	char		*line3 = get_next_line(fd);
	char		*line4 = get_next_line(fd);
	char		*line5 = get_next_line(fd);
	char		*line6 = get_next_line(fd);

	ASSERT_NE(line1, nullptr);
	EXPECT_STREQ(line1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum nec rutrum quam. Mauris scelerisque lectus sit amet nisi facilisis euismod. Nulla sed tortor eu metus tincidunt pellentesque eu eu diam. Quisque felis dolor, auctor nec ipsum quis, venenatis maximus lacus. Mauris nulla justo, vulputate et ante in, consectetur sagittis arcu. Donec posuere quam scelerisque vestibulum ultricies. Sed maximus rutrum turpis sit amet vehicula. Mauris ut sodales eros, eget gravida ante. Donec sed urna et tortor viverra imperdiet. Proin nec sem consequat, placerat est eu, tempus neque. Praesent vehicula pretium mi eu facilisis.\n");
	free(line1);

	ASSERT_NE(line2, nullptr);
	EXPECT_STREQ(line2, "Proin aliquam ex ut eleifend ullamcorper. Nam rhoncus nisl eu ex pretium varius. Praesent nec metus ornare, porttitor est nec, tempor velit. Phasellus purus est, hendrerit ac risus ut, mollis tristique ligula. Ut consequat, dui vitae tincidunt imperdiet, odio nisl porta massa, vel sollicitudin eros velit ultricies sapien. Vestibulum non ligula orci. In finibus nec orci vel eleifend. Curabitur rutrum ipsum ex, facilisis maximus lorem euismod nec.\n");
	free(line2);

	ASSERT_NE(line3, nullptr);
	EXPECT_STREQ(line3, "Nam tempor, augue ac rhoncus aliquet, nunc nisl euismod urna, at finibus velit augue a nulla. Nullam condimentum euismod mauris, sed molestie metus egestas eu. Sed vehicula eu libero vitae iaculis. Morbi ac mi massa. Pellentesque lorem magna, cursus egestas luctus ut, porta quis massa. Sed pretium elit vitae faucibus fringilla. Cras sagittis rhoncus sapien, in pharetra ligula pretium blandit. Fusce nec tempus ipsum. Nulla ut tellus turpis. Maecenas dictum consectetur augue, vel euismod nunc efficitur id. In dolor elit, dignissim at risus id, consectetur lacinia nisl. Vestibulum eu tincidunt diam. Ut ultrices vehicula dapibus.\n");
	free(line3);

	ASSERT_NE(line4, nullptr);
	EXPECT_STREQ(line4, "Fusce pretium eu odio at dictum. Aenean ullamcorper ullamcorper velit eget interdum. Proin ut tortor non lectus mattis sollicitudin. Nunc bibendum quam lacus, vel posuere justo vulputate non. Maecenas ac ultrices turpis. Nunc hendrerit justo eget nisl pellentesque molestie. Pellentesque neque ipsum, iaculis eget justo sit amet, molestie feugiat purus. Integer eget arcu nec dolor rutrum tempus. Maecenas faucibus ipsum mauris, vel porttitor dui elementum eget. Sed feugiat est ex, eget aliquet augue fermentum eu. Ut aliquet tellus at eros vulputate sodales. Aliquam a maximus diam, ac gravida arcu. Nulla sed molestie est. Ut volutpat neque ac leo sodales, eu maximus nisl dapibus. Donec molestie pharetra nisl, sit amet bibendum massa pulvinar eget. Mauris pretium lacus sit amet leo tempor, id varius diam vulputate.\n");
	free(line4);

	ASSERT_NE(line5, nullptr);
	EXPECT_STREQ(line5, "Aliquam erat volutpat. Nam sit amet est metus. Morbi consequat purus ut diam hendrerit tempor. Maecenas finibus ut mi at tristique. Vestibulum quam quam, ultricies sit amet sem at, gravida gravida velit. Morbi scelerisque turpis dolor, vestibulum congue lacus suscipit in. Donec quis purus in augue dictum vulputate at eu enim. Pellentesque eget egestas diam. Nam tincidunt justo dapibus massa faucibus faucibus sit amet id lorem. Vivamus molestie vel felis nec convallis. Integer facilisis leo nec ligula pellentesque, et varius velit scelerisque. Donec fringilla arcu ante, et blandit ligula dignissim ac.\n");
	free(line5);

	EXPECT_EQ(line6, nullptr);

	close(fd);
}

TEST(assets, lipsum)
{
	const int	fd = open("assets/lipsum.txt", O_RDONLY);

	char		*line1 = get_next_line(fd);
	char		*line2 = get_next_line(fd);
	char		*line3 = get_next_line(fd);
	char		*line4 = get_next_line(fd);
	char		*line5 = get_next_line(fd);
	char		*line6 = get_next_line(fd);
	char		*line7 = get_next_line(fd);
	char		*line8 = get_next_line(fd);
	char		*line9 = get_next_line(fd);
	char		*line10 = get_next_line(fd);
	char		*line11 = get_next_line(fd);
	char		*line12 = get_next_line(fd);
	char		*line13 = get_next_line(fd);
	char		*line14 = get_next_line(fd);
	char		*line15 = get_next_line(fd);
	char		*line16 = get_next_line(fd);
	char		*line17 = get_next_line(fd);
	char		*line18 = get_next_line(fd);
	char		*line19 = get_next_line(fd);
	char		*line20 = get_next_line(fd);
	char		*line21 = get_next_line(fd);

	ASSERT_NE(line1, nullptr);
	EXPECT_STREQ(line1, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla urna tellus, euismod sed finibus quis, pretium nec nulla. Vestibulum placerat laoreet dolor sed accumsan. Pellentesque pellentesque, odio sit amet euismod placerat, arcu enim fermentum nulla, et cursus libero eros sed eros. Proin tortor odio, tempor vel turpis in, molestie suscipit justo. Nulla facilisi. Phasellus non leo scelerisque, mollis enim in, fermentum orci. Proin commodo nunc a odio ornare, eget rutrum mi vehicula.\n");
	free(line1);

	ASSERT_NE(line2, nullptr);
	EXPECT_STREQ(line2, "Vestibulum sapien orci, convallis at fringilla sit amet, vulputate convallis nibh. Integer vestibulum, elit eget imperdiet finibus, est purus convallis sapien, at ultricies augue purus in ante. Aliquam sed venenatis enim. Proin dolor ligula, aliquet in dui eu, euismod tempor felis. Morbi mattis turpis ut orci iaculis, nec porta purus congue. Duis ac turpis quis mi gravida vehicula. Suspendisse potenti. Praesent ac leo eget ipsum rhoncus efficitur et vitae massa. Etiam dignissim hendrerit quam, id molestie augue interdum at. Cras pharetra sed ex nec euismod. Cras elementum suscipit erat, sit amet cursus enim bibendum sagittis. Donec posuere eros eu commodo tincidunt. Morbi sit amet lectus mattis, dictum arcu id, ultrices magna. Nam lacinia dui in tortor maximus, ac porta odio efficitur.\n");
	free(line2);

	ASSERT_NE(line3, nullptr);
	EXPECT_STREQ(line3, "Nam tempus maximus nunc. Ut et suscipit nunc. Aliquam sem sapien, egestas id scelerisque at, vulputate sed mi. Ut ultricies arcu eu vehicula rutrum. Integer hendrerit, dolor non consequat imperdiet, neque neque vestibulum justo, sed auctor magna velit eu nisi. Etiam fermentum nulla at tellus finibus varius. Curabitur vel tellus at tellus pellentesque accumsan. Morbi molestie eget ex nec ultrices. Proin et sagittis eros. Maecenas sapien massa, imperdiet sit amet sem id, auctor auctor mauris. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.\n");
	free(line3);

	ASSERT_NE(line4, nullptr);
	EXPECT_STREQ(line4, "Vivamus vel luctus dolor, nec scelerisque sem. Maecenas varius fermentum tortor ac porta. Proin ac vehicula nibh, sit amet iaculis leo. Mauris at pharetra ligula, eu aliquet ante. Quisque sodales fringilla euismod. Phasellus id lectus eget quam laoreet hendrerit. Sed ultrices varius magna vel aliquam. Phasellus consequat lacus vel dictum tempor. Vivamus in leo felis. Sed ac tortor at mi venenatis dapibus vitae at risus. Aenean quis nibh tincidunt, cursus lacus sed, vulputate ante.\n");
	free(line4);

	ASSERT_NE(line5, nullptr);
	EXPECT_STREQ(line5, "Duis sollicitudin dapibus tortor, quis condimentum nisi iaculis vel. Mauris vitae urna tempus, ornare nunc sit amet, porttitor orci. Nulla mattis sagittis sem et tempor. Nunc tempor odio dolor, vel finibus augue laoreet sed. Maecenas sed cursus ipsum, id congue massa. Sed id semper dolor. Integer dapibus eleifend turpis, quis pretium odio tincidunt sit amet. Ut commodo, est id ultrices fermentum, ante metus posuere arcu, sit amet vulputate dui odio eu felis. Vestibulum a nunc eget libero sollicitudin sollicitudin sit amet vel nisi. Vivamus interdum in elit quis lobortis. Morbi in mollis libero. Aliquam sodales sapien ut scelerisque mattis. Donec euismod mi turpis, id hendrerit dolor ullamcorper ac. Fusce consectetur tristique nulla eu molestie. Cras dapibus, nisi vel consequat auctor, libero enim placerat purus, in congue magna elit eget nunc. Mauris mollis vestibulum turpis varius malesuada.\n");
	free(line5);

	ASSERT_NE(line6, nullptr);
	EXPECT_STREQ(line6, "Proin nec pulvinar lectus, ut posuere nulla. Nunc ac libero non justo eleifend fringilla. Aenean sit amet vulputate nisi. Nullam vel luctus neque, congue finibus nulla. Praesent quis est feugiat, molestie ligula sed, auctor purus. Vestibulum lacinia lectus id nisl lobortis, eget faucibus elit consequat. Fusce metus orci, placerat at eros ut, pulvinar egestas justo. Duis ac elit molestie, suscipit nulla eu, auctor metus. Mauris fermentum ipsum vitae turpis tincidunt molestie. Fusce a placerat arcu, ut cursus sem. Phasellus nec sapien eu nisl ultricies venenatis. Aenean non ante porta, consectetur nunc sed, aliquet dolor.\n");
	free(line6);

	ASSERT_NE(line7, nullptr);
	EXPECT_STREQ(line7, "Cras molestie ligula id est laoreet, eu placerat nibh accumsan. Aliquam et lorem non turpis pulvinar euismod. Maecenas porta leo tortor. Praesent lectus purus, mattis eu tempor quis, placerat non velit. Vivamus tempus sapien et felis posuere, in volutpat turpis mollis. Nulla metus ligula, feugiat at rutrum eget, efficitur at erat. Morbi id posuere urna. Praesent sed urna et mauris aliquet lacinia et consectetur tellus. Proin ornare nisl sed turpis imperdiet fringilla. Vestibulum sagittis ante eleifend, commodo risus tempor, feugiat orci. Sed id leo finibus, dapibus tortor in, aliquet elit. Donec luctus dapibus nulla ut vulputate. Curabitur nec leo eget justo lacinia auctor non id elit.\n");
	free(line7);

	ASSERT_NE(line8, nullptr);
	EXPECT_STREQ(line8, "Quisque vel orci sed lorem ullamcorper malesuada ac at velit. Quisque massa tortor, placerat nec luctus non, eleifend sed nulla. Etiam egestas vehicula tempor. Suspendisse porttitor fringilla sem. Mauris id facilisis est. Aliquam lectus nibh, tincidunt sit amet pretium sed, porta sit amet orci. Suspendisse lobortis tellus quis nibh accumsan, vitae tempus massa fringilla. Integer vel metus placerat, pellentesque felis quis, porttitor urna. Nullam finibus justo ac risus semper, sed cursus sem hendrerit. Aliquam ut quam at ipsum tincidunt laoreet. Mauris in enim elementum, vehicula risus et, interdum nisl. Ut finibus facilisis nisl ac consequat. Duis luctus nulla pulvinar sapien finibus malesuada. Sed ut consequat tortor.\n");
	free(line8);

	ASSERT_NE(line9, nullptr);
	EXPECT_STREQ(line9, "Donec sit amet sagittis augue. Morbi ut finibus nibh. Fusce tempus iaculis volutpat. Pellentesque posuere enim eros, sed viverra turpis faucibus id. Aliquam ac egestas ante, quis placerat neque. In placerat lorem id eros congue vehicula. Vestibulum id dolor et ex volutpat mollis. Duis imperdiet nunc nec euismod sollicitudin.\n");
	free(line9);

	ASSERT_NE(line10, nullptr);
	EXPECT_STREQ(line10, "Phasellus aliquam arcu ac congue fermentum. Nulla sit amet lacus est. Nulla nec lorem nec nisl tempor sagittis sed in dolor. Ut in varius nisi. Phasellus gravida ex convallis purus finibus, at lobortis ipsum porttitor. Proin tristique libero odio, a laoreet lacus consequat sit amet. In feugiat lobortis eros vitae sollicitudin. Donec in gravida orci.\n");
	free(line10);

	ASSERT_NE(line11, nullptr);
	EXPECT_STREQ(line11, "Praesent lacinia quam porta massa pretium, sed luctus ante mollis. Morbi sit amet ipsum varius, lobortis quam sit amet, sagittis nibh. Pellentesque id consequat eros, eget pulvinar purus. Aenean vitae eros molestie, aliquam metus in, fringilla magna. Nulla eu orci velit. Etiam tristique metus quis bibendum ultricies. Suspendisse nec elit nunc. Duis ex nibh, pretium vitae nulla et, sagittis viverra lacus. Nunc eleifend molestie sagittis. Nullam fringilla, dui nec semper vehicula, lectus erat efficitur lectus, sit amet hendrerit sem ante quis magna. Integer ut vehicula quam. Duis elementum consequat metus, in interdum libero sodales sit amet. Mauris non congue leo. Etiam consequat, arcu a scelerisque viverra, augue justo elementum libero, dapibus scelerisque diam lectus eget nisl. Sed eget varius leo.\n");
	free(line11);

	ASSERT_NE(line12, nullptr);
	EXPECT_STREQ(line12, "Morbi vel augue non ipsum auctor faucibus in efficitur enim. Vestibulum id dictum ipsum. Quisque eget pulvinar odio. Phasellus nec pulvinar lorem. Ut placerat hendrerit posuere. Sed risus ex, finibus nec sapien et, blandit bibendum ipsum. Quisque sit amet lacus tristique, ultrices risus in, varius ipsum. Mauris vel cursus est, eget tincidunt risus. Sed tincidunt eleifend augue, eu fringilla enim vestibulum vel. Nunc at aliquet elit. Cras in luctus sapien. Suspendisse gravida ac nibh a suscipit.\n");
	free(line12);

	ASSERT_NE(line13, nullptr);
	EXPECT_STREQ(line13, "Etiam tristique dignissim maximus. Morbi in elementum ligula, vel congue nulla. Proin sed tortor eu nibh dignissim molestie a non nunc. Aenean elementum ante ut felis semper feugiat. Morbi quis volutpat nisl. Morbi mauris nibh, accumsan sed imperdiet at, porta vel est. Nunc non convallis mi, ac faucibus ante.\n");
	free(line13);

	ASSERT_NE(line14, nullptr);
	EXPECT_STREQ(line14, "Aenean interdum nisl quis fringilla eleifend. Nam et molestie turpis. Nulla at blandit ex. Etiam interdum tellus sit amet orci interdum luctus. In maximus dolor eu vulputate hendrerit. Fusce feugiat, metus ornare varius auctor, lorem dui egestas lorem, et aliquam metus massa a nulla. Sed viverra nec metus a venenatis. Mauris iaculis metus erat, in hendrerit orci aliquam egestas. Duis commodo tempor tellus vitae eleifend. Pellentesque orci eros, finibus in dolor vel, vestibulum porttitor metus. Vivamus semper porta nulla quis sagittis.\n");
	free(line14);

	ASSERT_NE(line15, nullptr);
	EXPECT_STREQ(line15, "Curabitur et odio rutrum, imperdiet arcu tempus, venenatis lorem. Ut luctus risus est, non accumsan augue dictum vel. Nullam felis ante, iaculis eu massa sit amet, condimentum viverra velit. Sed sed pretium augue, sit amet lacinia metus. Donec at erat non augue tincidunt venenatis sed nec tortor. Phasellus vehicula tortor non risus convallis tempus. Sed eu mattis massa. Maecenas lectus ex, blandit nec urna eu, tempus bibendum nunc. Proin et efficitur eros. Quisque ultricies velit vitae diam sollicitudin viverra. Duis facilisis sed est nec vestibulum. Aliquam sit amet dolor ex. Donec pulvinar fermentum nulla, ut sollicitudin quam malesuada euismod. Nulla placerat bibendum augue a porttitor. Nulla sed luctus lorem.\n");
	free(line15);

	ASSERT_NE(line16, nullptr);
	EXPECT_STREQ(line16, "Ut vel metus neque. Etiam vitae sodales dolor, non vulputate lectus. In commodo felis id aliquam varius. Suspendisse et auctor lacus. Curabitur efficitur elit vestibulum, tristique dolor non, bibendum nibh. Nulla at ex sed sem consequat hendrerit. Quisque eget ornare nunc, eu laoreet quam. Pellentesque sodales massa et turpis pharetra lacinia. Fusce suscipit eleifend tempor. Proin lobortis vel mi non molestie. Mauris condimentum nunc risus, a molestie metus varius eu. Mauris vel ante aliquet leo mattis mattis non id metus. Suspendisse mollis consequat ante aliquam semper. Fusce sed imperdiet urna. Proin elit lectus, mollis eu sollicitudin vitae, sagittis mattis ante.\n");
	free(line16);

	ASSERT_NE(line17, nullptr);
	EXPECT_STREQ(line17, "Donec sodales dolor ac feugiat dictum. Vivamus feugiat purus orci. Aliquam erat volutpat. Maecenas tristique libero ligula, vel lacinia purus vulputate at. In hac habitasse platea dictumst. Aliquam erat volutpat. Nulla consequat metus ut mi consectetur, eu tempor sem vulputate.\n");
	free(line17);

	ASSERT_NE(line18, nullptr);
	EXPECT_STREQ(line18, "Duis semper purus mi, ac sollicitudin arcu pretium eget. Nam augue justo, auctor id odio et, rutrum consequat massa. Suspendisse pellentesque fringilla ultricies. Proin ac mollis ex, ac varius ligula. Pellentesque venenatis sollicitudin dapibus. Fusce ac mi eu diam suscipit imperdiet vitae at tellus. Quisque vel orci vestibulum, laoreet mi id, commodo dolor. Suspendisse potenti. Fusce nec mauris bibendum nibh scelerisque imperdiet. Ut dictum erat lacus, ac volutpat ante varius quis.\n");
	free(line18);

	ASSERT_NE(line19, nullptr);
	EXPECT_STREQ(line19, "Duis augue elit, consequat vel odio vel, volutpat facilisis mi. Pellentesque scelerisque consectetur eros in volutpat. Morbi augue est, efficitur a ullamcorper sit amet, ornare sit amet leo. Curabitur tincidunt eget augue a dictum. Sed nec dolor at urna tincidunt interdum ac a risus. Suspendisse fringilla nisl et ante egestas convallis. Vestibulum ut lorem a purus sollicitudin pellentesque non vel orci. In efficitur nisl odio, sit amet fringilla magna porttitor ac.\n");
	free(line19);

	ASSERT_NE(line20, nullptr);
	EXPECT_STREQ(line20, "Nulla faucibus placerat odio, in porttitor neque. Vestibulum porta enim ac orci porta suscipit. Praesent mollis fringilla gravida. Vestibulum pretium dapibus magna, sed aliquet urna feugiat vel. Interdum et malesuada fames ac ante ipsum primis in faucibus. Phasellus vulputate augue nulla, eu ultrices urna molestie eget. In vel urna pharetra, gravida libero a, ullamcorper magna. Morbi sit amet pellentesque metus, et dignissim magna. Nulla consequat hendrerit interdum. Proin turpis felis, molestie ac auctor vel, pulvinar id elit.\n");
	free(line20);

	EXPECT_EQ(line21, nullptr);

	close(fd);
}
