/*
 * test_time_boost1.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: fyu
 */


#include <boost/date_time/posix_time/posix_time.hpp>
#include <stdlib>
#include <iostream>
namespace pt = boost::posix_time;
using namespace std;
int main()
{
    pt::ptime current_date_microseconds = pt::microsec_clock::local_time();
    long milliseconds = current_date_microseconds.time_of_day().total_milliseconds();
    pt::time_duration current_time_milliseconds = pt::milliseconds(milliseconds);
    pt::ptime current_date_milliseconds(current_date_microseconds.date(),current_time_milliseconds);
    cout << "Microseconds: "
    		<< current_date_microseconds << endl
            << "Milliseconds: "
			<< current_date_milliseconds << endl;
    		// Microseconds: 2013-Jul-12 13:37:51.699548 Milliseconds: 2013-Jul-12 13:37:51.699000
}

