/*@Description: Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/


 //Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
 

/**
找到newInterval.start所在区间[intervals[i].start, intervals[i + 1].start)，然后比较newInterval.start与
intervals[i].end的大小，并确定newInterval.end所在区间，然后进行元素的替换、插入和移除操作。总之，这是一种
很蠢的做法，考虑的情况太多，而且对于边界处理需额外考虑。
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0, size = intervals.size();
        if(intervals.empty())
            return { newInterval };
        //首先确定newInterval.start大于第一个元素，否则会遍历到最后使得i = size - 1；如果不大于，则i = 0
        if(newInterval.start > intervals[0].start)	
        {  
            for(i = 0; i < size - 1; i++)
            {
                if(newInterval.start >= intervals[i].start && newInterval.start < intervals[i + 1].start)
                     break;
            }
        }
        
        if(newInterval.start <= intervals[i].end)
        {
        	// i == 0的情况特殊处理，小于成立则在数组首位插入新元素，否则按正常流程确定newInterval.end所在区间
            if(i == 0 && newInterval.end < intervals[i].start)	
            {
                intervals.insert(intervals.begin(), newInterval);
                return intervals;
            }
            int j = i, begin = i;
            for(; j < size - 1; j++)
            {
                if(newInterval.end >= intervals[j].start && newInterval.end < intervals[j + 1].start)
                    break;
            }
            intervals[i].start = min(intervals[i].start, newInterval.start);
            intervals[i].end = max(intervals[j].end, newInterval.end);
            if(begin < j)
                intervals.erase(intervals.begin() + begin + 1, intervals.begin() + j + 1);
            return intervals;                
        }
        
        if(newInterval.start > intervals[i].end)
        {
        	// i == size - 1时，必存在newInterval.start>=intervals[size-1].start，如果newInterval.start 
        	// <= intervals[size-1].end，则在上一种情况中考虑，否则在末尾插入新元素
            if(i == size - 1)
            {
                intervals.insert(intervals.end(), newInterval);
                return intervals;
            }
            //新元素正好在两个区间之间，需要插入
            if(newInterval.end < intervals[i + 1].start)
            {
                intervals.insert(intervals.begin() + i + 1, newInterval);
                return intervals;
            }
            else
            {
                int j = i + 1, begin = i + 1;
                for(; j < size - 1; j++)
                {
                    if(newInterval.end >= intervals[j].start && newInterval.end < intervals[j + 1].start)
                        break;
                }
                intervals[begin].start = newInterval.start;
                intervals[begin].end = max(newInterval.end, intervals[j].end);
                if(begin < j)
                    intervals.erase(intervals.begin() + begin + 1, intervals.begin() + j + 1);
                return intervals;
            }
        }
    }
};

/**
先拷贝newInterval前的所有元素，然后比较新元素和数组中每一个元素的大小，start取较小值，end取较大值，
直到newInterval.end < intervals[i].start，然后拷贝剩余元素，很直观的方法
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int i = 0;
        for(; i < intervals.size() && intervals[i].end < newInterval.start; i++)
            result.push_back(intervals[i]);
        for(; i < intervals.size() && intervals[i].start <= newInterval.end; i++)
        {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
        result.push_back(newInterval);
        for(; i < intervals.size(); i++)
            result.push_back(intervals[i]);
        return result;
    }
};

/**
思路和方法二一致，只是不需要额外的数组存储元素，而是直接在原来的数组上删除元素，并插入新元素（和删除元素合并后）
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0;
        for(; i < intervals.size() && intervals[i].end < newInterval.start; i++);
        int begin = i;
        for(; i < intervals.size() && intervals[i].start <= newInterval.end; i++)
        {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
        intervals.erase(intervals.begin() + begin, intervals.begin() + i);
        intervals.insert(intervals.begin() + begin, newInterval);
        return intervals;
    }
};

/**
STL equal_range确定边界
*/
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto compare = [] (const Interval &intv1, const Interval &intv2) { return intv1.end < intv2.start; };
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
        auto itr1 = range.first, itr2 = range.second;
        if (itr1 == itr2) 
        {
            intervals.insert(itr1, newInterval);
        } 
        else 
        {
            itr2--;
            itr2->start = min(newInterval.start, itr1->start);
            itr2->end = max(newInterval.end, itr2->end);
            intervals.erase(itr1, itr2);
        }
        return intervals;
    }
};