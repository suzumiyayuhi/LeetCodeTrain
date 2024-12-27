class ExamRoom {
public:
    int N;
    set<pair<int, int>, std::function<bool(const std::pair<int, int>&, const std::pair<int, int>&)>> interval;
    unordered_map<int, int> left;
    unordered_map<int, int> right;

    ExamRoom(int n) : N(n), interval(compare__())
    {
        
    }

    std::function<bool(const std::pair<int, int>&, const std::pair<int, int>&)> compare__() const 
    {
        return [this](const std::pair<int, int>& a, const std::pair<int, int>& b) 
        {
            int d1, d2;
            if(a.first == -1 || a.second == N)
                d1 = a.second - a.first - 1;
            else
                d1 = (a.second - a.first) / 2;
            
            if(b. first == -1 || b. second == N)
                d2 = b.second - b.first - 1;
            else
                d2 = (b.second - b.first) / 2;

            return d1 == d2 ? a.first < b.first : d1 > d2;
        };
    }

    int seat() 
    {
        if(interval.empty())
        {
            interval.insert({-1, 0});
            interval.insert({0, N});
            left[0] = -1;
            right[-1] = 0;
            left[N] = 0;
            right[0] = N;
            return 0;
        }

        pair<int, int> tem = *interval.begin();
        int p;
        if(tem.first == -1)
        {
            p = 0;
        }
        else if(tem.second == N)
        {
            p = N - 1;
        }
        else
        {
            p = (tem.first + tem.second) / 2;
        }
        
        interval.erase(interval.begin());
        interval.insert({tem.first, p});
        interval.insert({p, tem.second});
        left[p] = tem.first;
        right[p] = tem.second;
        left[tem.second] = p;
        right[tem.first] = p;
        return p;
        
    }
    
    void leave(int p) 
    {
        int a = left[p];
        int b = right[p];
        interval.erase({a, p});
        interval.erase({p, b});
        interval.insert({a, b});
        left.erase(p);
        right.erase(p);
        right[a] = b;
        left[b] = a;
    }
};