/*@Description: Merge Intervals
Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


/**
将所有元组按照第一个元素start从小到大排序，然后比较当前元组的end和下一个元组的start的大小，
如果存在重叠的区间，则将end值更新为两个元组中的较大end值，直到相邻两个元组不存在重叠的区间，
将之前的扩展元组保存，并继续往下遍历
*/
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty())
            return result;
        if(intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](const Interval& r1, const Interval& r2) {return r1.start < r2.start; });
        Interval tmp;
        for(int i = 1; i < intervals.size() + 1; i++)	//终止条件为size + 1，确保可以添加最后一个元组
        {
            tmp.start = intervals[i - 1].start;
            while(i < intervals.size() && intervals[i].start <= intervals[i - 1].end)
            {
                if(intervals[i].end < intervals[i - 1].end)
                   intervals[i].end = intervals[i - 1].end;
                i++;
            }
            tmp.end = intervals[i - 1].end;
            result.push_back(tmp);
        }
        return result;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), [](const Interval& r1, const Interval& r2) {return r1.start < r2.start; });
        Interval tmp(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(tmp.end >= intervals[i].start)
                tmp.end = max(tmp.end, intervals[i].end);
            else
            {
                result.push_back(tmp);
                tmp = intervals[i];
            }
        }
        result.push_back(tmp);	//添加最后一个元组
        return result;
    }
};

/**
先将一个单独的元组保存到数组中，然后遍历后续元组，判断是否需要更新元组的end值
*/
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](const Interval& r1, const Interval& r2) {return r1.start < r2.start; });
        vector<Interval> result({ intervals[0] });
        for (int i = 1; i < intervals.size(); i++) 
        {
            if (result.back().end < intervals[i].start) 
                result.push_back(intervals[i]);
            else
                result.back().end = max(result.back().end, intervals[i].end);
        }
        return result;
    }
};