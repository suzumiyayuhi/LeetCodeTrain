class MyCalendar {
public:
    set<pair<int, int>> interval;
    MyCalendar() {

    }
    
    bool book(int startTime, int endTime) {
        pair<int, int> tem = {startTime, endTime};
        if(interval.empty())
        {
            interval.insert(tem);
            return true;
        }

        auto it = interval.lower_bound(tem);
        auto temIt = it;
        it--;
        
        if(temIt == interval.end())
        {
            if(it->second <= startTime)
            {
                interval.insert(tem);
                return true;
            }
            return false;
        }
        
        if(it == temIt)
        {
            if(it->first >= endTime)
            {
                interval.insert(tem);
                return true;
            }
            return false;
        }

        if(temIt->first >= endTime && it->second <= startTime)
        {
            interval.insert(tem);
            return true;
        }
        return false;
    }
};