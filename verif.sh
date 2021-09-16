
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
echo -n "${Purple}valgrind --leak-check=full ./so_long -> ${Reset}"; valgrind --leak-check=full ./so_long
echo -n "${Purple}valgrind --leak-check=full ./so_long test-> ${Reset}"; valgrind --leak-check=full ./so_long test
echo -n "${Purple}valgrind --leak-check=full ./so_long includes/-> ${Reset}"; valgrind --leak-check=full ./so_long includes/
echo -n "${Purple}valgrind --leak-check=full ./so_long maps/t.b-> ${Reset}"; valgrind --leak-check=full ./so_long maps/t.b
echo -n "${Purple}valgrind --leak-check=full ./so_long maps/t.be-> ${Reset}"; valgrind --leak-check=full ./so_long maps/t.be
echo -n "${Purple}valgrind --leak-check=full ./so_long maps/t.berasdf-> ${Reset}"; valgrind --leak-check=full ./so_long maps/t.berasdf

valgrind --leak-check=full ./so_long maps/test.ber
