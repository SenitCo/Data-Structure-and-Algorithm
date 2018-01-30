/*@Description: Max Points on a Line
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/


//Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 
/**
穷举所有两点组合成一条直线的可能，根据其斜率进行计数统计。此法直接计算斜率，存在精度问题
*/
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int size = points.size();
        if(size < 2)    return size;
        int result = 0;
        for(int i = 0; i < size; i++)
        {
            int curmax = 1, dup = 0, vcnt = 0;
            map<double, int> mp;
            for(int j = i + 1; j < size; j++)
            {
                double x = points[i].x - points[j].x;
                double y = points[i].y - points[j].y;
                if(x == 0 && y == 0)
                    dup++;
                else if(x == 0)
                {
                    if(vcnt == 0)
                        vcnt = 2;
                    else
                        vcnt++;
                    curmax = max(curmax, vcnt);
                }
                else
                {
                    double k = y / x;
                    if(mp[k] == 0)
                        mp[k] = 2;
                    else
                        mp[k]++;
                    curmax = max(curmax, mp[k]);
                }
            }
            result = max(result, curmax + dup);
        }
        return result;
    }
};

/**
穷举所有由两点确定的直线，但斜率不是直接用一个double型数据表示，对于斜率的分数表示 k = y/x，
通过辗转相除法求得y和x的最大公约数gcd，然后同时除以gcd，得到斜率的最简分数表示 k = y0/x0，这样
斜率就可以通过(x0, y0)唯一确定，没有浮点数表示所带来的精度问题
*/
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int size = points.size();
        if (size < 2) return size;

		map<int,map<int,int>> map;
		int result = 0;

		for (unsigned int i = 0; i < size; i++)
        {
			map.clear();
			int localmax = 0, overlap = 0;
			for (unsigned int j = i + 1; j < size; j++)
            {
				int x = points[j].x - points[i].x;
				int y = points[j].y - points[i].y;
				if (x == 0 && y == 0)
                {
					overlap++;
					continue;
				}
				int gcd = generateGCD(x, y);
				if (gcd != 0)	//(x, 0)最后都统一表示为(1, 0)
                {
					x /= gcd;
					y /= gcd;
				}
				int curr = ++map[x][y];
				localmax = max(curr, localmax);
			}
			result = max(result, localmax + overlap + 1);
		}
		return result;
	}
private:
	int generateGCD(int a, int b)	//辗转相除法求最大公约数
    {
		if (b == 0) return a;
		return generateGCD(b, a % b);
    }
};