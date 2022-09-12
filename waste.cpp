#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/special_defs.hpp>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>

using namespace boost::asio;

int main(int argc, char** argv) {
	io_context ic;
	io_context::strand is (ic);
	deadline_timer dt (ic);

	if (argc > 1 && argv[1][0] == 'n')
		dt.expires_at(boost::posix_time::ptime(boost::date_time::max_date_time));
	else
		dt.expires_at(boost::posix_time::pos_infin);

	for (int i = 0; i < 1024 * 64; ++i)
		spawn(is, [&dt](yield_context yc) { dt.async_wait(yc); });

	ic.run();
}
