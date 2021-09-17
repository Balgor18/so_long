#!bin/sh

Reset="\033[0m"
Red="\033[1;49;31m"
Green="\033[1;49;32m"
Yellow="\033[1;49;33m"
Blue="\033[1;49;34m"
Purple="\033[1;49;35m"
Cyan="\033[1;49;36m"

echo "\n";
echo "${Red}███╗   ██╗ ██████╗ ██████╗ ███╗   ███╗██╗███╗   ██╗███████╗████████╗████████╗███████╗${Reset}";
echo "${Yellow}████╗  ██║██╔═══██╗██╔══██╗████╗ ████║██║████╗  ██║██╔════╝╚══██╔══╝╚══██╔══╝██╔════╝${Reset}";
echo "${Green}██╔██╗ ██║██║   ██║██████╔╝██╔████╔██║██║██╔██╗ ██║█████╗     ██║      ██║   █████╗${Reset}";
echo "${Cyan}██║╚██╗██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║╚██╗██║██╔══╝     ██║      ██║   ██╔══╝${Reset}";
echo "${Blue}██║ ╚████║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██║ ╚████║███████╗   ██║      ██║   ███████╗${Reset}";
echo "${Purple}╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝   ╚═╝      ╚═╝   ╚══════╝${Reset}";
echo "\n";

sleep 3; norminette **/*.h; norminette **/*.c; norminette *h; norminette *.c;

echo "\n";
echo "${Red}███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗    ██████╗ ██╗   ██╗██╗     ███████╗███████╗${Reset}";
echo "${Yellow}████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝    ██╔══██╗██║   ██║██║     ██╔════╝██╔════╝${Reset}";
echo "${Green}██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗      ██████╔╝██║   ██║██║     █████╗  ███████╗${Reset}";
echo "${Cyan}██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝      ██╔══██╗██║   ██║██║     ██╔══╝  ╚════██║${Reset}";
echo "${Blue}██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗    ██║  ██║╚██████╔╝███████╗███████╗███████║${Reset}";
echo "${Purle}╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝    ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝╚══════╝${Reset}";
echo "\n";

sleep 3; make; make clean; make fclean; make re


echo "\n${Green}SO LONG ERROR MANAGING TESTS:${Reset}\n"; sleep 3;

echo -n "${Purple}./so_long -> ${Reset}"; ./so_long
echo -n "${Purple}./so_long test-> ${Reset}"; ./so_long test
echo -n "${Purple}./so_long includes/-> ${Reset}"; ./so_long includes/
echo -n "${Purple}./so_long maps/t.b-> ${Reset}"; ./so_long maps/t.b
echo -n "${Purple}./so_long maps/t.be-> ${Reset}"; ./so_long maps/t.be
echo -n "${Purple}./so_long maps/t.berasdf-> ${Reset}"; ./so_long maps/t.berasdf
: <<'END'
echo "\n${Green}SO LONG ERROR MANAGING TESTS OUTPUT:${Reset}\n"; sleep 3;
echo -n "${Purple}./so_long > /dev/null 2>tmp-> ${Reset}"; ./so_long >/dev/null 2>tmp
echo -n "${Purple}./so_long test-> ${Reset}"; ./so_long test
echo -n "${Purple}./so_long includes/-> ${Reset}"; ./so_long includes/
echo -n "${Purple}./so_long maps/t.b-> ${Reset}"; ./so_long maps/t.b
echo -n "${Purple}./so_long maps/t.be-> ${Reset}"; ./so_long maps/t.be
echo -n "${Purple}./so_long maps/t.berasdf-> ${Reset}"; ./so_long maps/t.berasdf
END
echo "\n${Green}SO LONG ERROR MANAGING TESTS WITH VALGRIND :${Reset}\n"; sleep 3;
echo -n "${Purple}valgrind --leak-check=full ./so_long -> ${Reset}"; valgrind --leak-check=full ./so_long
echo -n "${Purple}valgrind --leak-check=full ./so_long test-> ${Reset}"; valgrind --leak-check=full ./so_long test
echo -n "${Purple}valgrind --leak-check=full ./so_long includes/-> ${Reset}"; valgrind --leak-check=full ./so_long includes/
echo -n "${Purple}valgrind --leak-check=full ./so_long maps/t.b-> ${Reset}"; valgrind --leak-check=full ./so_long maps/t.b
echo -n "${Purple}valgrind --leak-check=full ./so_long maps/t.be-> ${Reset}"; valgrind --leak-check=full ./so_long maps/t.be
echo -n "${Purple}valgrind --leak-check=full ./so_long maps/t.berasdf-> ${Reset}"; valgrind --leak-check=full ./so_long maps/t.berasdf

echo "\n${Green}SO LONG ERROR MAP :${Reset}\n"; sleep 3;
echo -n "${Purple}./so_long maps/error_dimension.ber-> ${Reset}"; ./so_long maps/error_dimension.ber
echo -n "${Purple}./so_long maps/error_close_map_first_or_last.ber-> ${Reset}"; ./so_long maps/error_close_map_first_or_last.ber
echo -n "${Purple}./so_long maps/error_close_map_middle_line.ber-> ${Reset}"; ./so_long maps/error_close_map_middle_line.ber

echo -n "${Purple}valgrind --leak-check=full ./so_long maps/error_dimension.ber-> ${Reset}"; valgrind --leak-check=full ./so_long maps/error_dimension.ber
echo -n "${Purple}valgrind --leak-check=full ./so_long maps/error_close_map_first_or_last.ber-> ${Reset}"; valgrind --leak-check=full ./so_long maps/error_close_map_first_or_last.ber
echo -n "${Purple}valgrind --leak-check=full ./so_long maps/error_close_map_middle_line.ber-> ${Reset}"; valgrind --leak-check=full ./so_long maps/error_close_map_middle_line.ber

echo "\n${Green}SO LONG TESTS :${Reset}\n"; sleep 3;
echo -n "${Purple}./so_long maps/test.ber-> ${Reset}"; ./so_long maps/test.ber
echo -n "${Purple}valgrind --leak-check=full ./so_long maps/test.ber-> ${Reset}"; valgrind --leak-check=full ./so_long maps/test.ber
valgrind --leak-check=full ./so_long maps/test.ber
