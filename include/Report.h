/*
 * Report.h
 *
 *  Created on: 9 sty 2018
 *      Author: Mateusz
 */

#ifndef REPORT_H_
#define REPORT_H_

#include"types.h"
#include<set>

class IReportNotifier
{
public:
	virtual bool shouldGenerateReport(Time)=0;
};

class SpecificTurnsReportNotifier : public IReportNotifier
{
private:
	std::set<Time> turns;
public:
	SpecificTurnsReportNotifier(std::set<Time>);
	bool shouldGenerateReport(Time) override;
};

class IntervalReportNotifier : public IReportNotifier
{
private:
	TimeOffset interval;
public:
	IntervalReportNotifier(TimeOffset);
	bool shouldGenerateReport(Time) override;
};

#endif /* REPORT_H_ */
