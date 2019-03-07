#pragma once

template <typename Underlying_type>
CallableRangeAccrual<Underlying_type>::CallableRangeAccrual(){}

template <typename Underlying_type>
CallableRangeAccrual<Underlying_type>::CallableRangeAccrual(CallableRangeAccrual const& other)
    : payoff (other.payoff),
    rangeMax(other.rangeMax),
    rangeMin(other.rangeMin),
    fixedLegTenor(other.fixedLegTenor),
    varLegTenor(other.varLegTenor)
{}

template <typename Underlying_type>
CallableRangeAccrual<Underlying_type>::CallableRangeAccrual(CallableRangeAccrual && other)
    : payoff(std::move(other.payoff)),
    rangeMax(std::move(other.rangeMax)),
    rangeMin(std::move(other.rangeMin)),
    fixedLegTenor(std::move(other.fixedLegTenor)),
    varLegTenor(std::move(other.varLegTenor))
{}

template <typename Underlying_type>
CallableRangeAccrual<Underlying_type>::CallableRangeAccrual(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar,
    int fixedIncrement,
    int varIncrement,
    ql::Rate const& payoff_,
    Underlying_type const& rangeMax_,
    Underlying_type const& rangeMin_
)
    : payoff(payoff_),
    rangeMax(rangeMax_),
    rangeMin(rangeMin_)
{
    /*
        Must check before initializing!
    */
    checkLimitDates(startDate, true, calendar);
    checkLimitDates(endDate  , false, calendar);
    fixedLegTenor = generateTenor(
        startDate,
        endDate,
        calendar,
        fixedIncrement
    );
    varLegTenor = generateTenor(
        startDate,
        endDate,
        calendar,
        varIncrement
    );
}

template <typename Underlying_type>   
CallableRangeAccrual<Underlying_type>::~CallableRangeAccrual(){}

template <typename TT>
std::ostream& operator<<(std::ostream& oStream, CallableRangeAccrual<TT> const& cra){
    oStream << 
    "Callable range accrual contract info:" << std::endl <<

    "start date: "             << cra.fixedLegTenor.front() << std::endl <<
    "end date: "               << cra.fixedLegTenor.back()  << std::endl <<

    "max range of the range : " << cra.rangeMax << std::endl <<
    "min range of the range : " << cra.rangeMin << std::endl <<

    "payoff: "                 << cra.payoff  << std::endl <<
    "cra.fixedLegTenor[1]= "   << cra.fixedLegTenor[1] << std::endl <<
    "cra.varLegTenor  [1]= "   << cra.varLegTenor  [1] << std::endl <<

    "size of fixed tenor: "    << cra.fixedLegTenor.size() << std::endl <<
    "size of variable tenor: " << cra.varLegTenor.size();
    return oStream;
}

// double computeFixedLegCoupons(ql::Date const &fromDate, ql::Date const &toDate);
// double computeVarLegCoupons(ql::Date const &fromDate, ql::Date const &toDate)
// double computeActualizedCashFlow(ql::Date const &date);
// double computeExerciseValue(ql::Date const &date);
// double computeHoldValue(ql::Date const &date)
// double computeLSPrice();
