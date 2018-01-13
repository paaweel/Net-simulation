/*
 * Report.cpp
 *
 *  Created on: 9 sty 2018
 *      Author: Mateusz
 */

#include "../include/Report.h"
#include "Report.h"


SpecificTurnsReportNotifier::SpecificTurnsReportNotifier(std::set<Time> _turns)
{
	turns = _turns;
}

bool SpecificTurnsReportNotifier::shouldGenerateReport(Time _turn)
{
	return turns.find(_turn) != turns.end() ? false : true;
}

IntervalReportNotifier::IntervalReportNotifier(TimeOffset _interval)
{
	interval = _interval;
}

bool IntervalReportNotifier::shouldGenerateReport(Time _turn)
{
	return _turn % interval == 0 ? true : false;
}


