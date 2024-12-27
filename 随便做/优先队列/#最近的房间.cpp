struct record
{
    int originId;
    int roomSize;
    int roomId;
    record(int _originId, int _roomSize, int _roomId)
    {
        this->originId = _originId;
        this->roomSize = _roomSize;
        this->roomId = _roomId;
    }
};

bool compare__(const record& a, const record& b)
{
    return a.roomSize > b.roomSize;
}

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<record> roomRecords;
        vector<record> queryRecords;
        for(int i = 0; i < rooms.size(); i++)
        {
            roomRecords.emplace_back(record(i, rooms[i][1], rooms[i][0]));
        }
        for(int i = 0; i < queries.size(); i++)
        {
            queryRecords.emplace_back(record(i, queries[i][1], queries[i][0]));
        }
        sort(roomRecords.begin(), roomRecords.end(), compare__);
        sort(queryRecords.begin(), queryRecords.end(), compare__);

        vector<int> res(queries.size(), -1);
        set<int> curRoomIdSet;
        int j = 0;
        for(int i = 0; i < queryRecords.size(); i++)
        {
            int curRoomID = queryRecords[i].roomId;
            int curRoomSize = queryRecords[i].roomSize;
            int curQueryID = queryRecords[i].originId;
            while(j < roomRecords.size() && roomRecords[j].roomSize >= curRoomSize)
            {
                curRoomIdSet.insert(roomRecords[j].roomId);
                j++;
            }

            int dist = INT_MAX;
            auto it = curRoomIdSet.lower_bound(curRoomID);
            if(it != curRoomIdSet.begin())
            {
                auto p = prev(it);
                dist = curRoomID - *p;
                res[curQueryID] = *p;
            }
            if(it != curRoomIdSet.end() && *it - curRoomID < dist)
                res[curQueryID] = *it;
        }
        return res;
    }
};
