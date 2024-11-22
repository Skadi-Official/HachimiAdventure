#ifndef _PATH_H_
#define _PATH_H_

#include "vector2.h"

#include <vector>
/*Path类是对角色移动路径的封装
* 通过它记录的路径顶点计算任意进度的路径坐标
*/
class Path
{
public:
	Path(const std::vector<Vector2>& point_list)
	{
		this->point_list = point_list;

		for (size_t i = 1; i < point_list.size(); i++)
		{
			float segment_len = (point_list[i] - point_list[i - 1]).length();
			segment_len_list.push_back(segment_len);
			total_length += segment_len;
		}
	}

	~Path() = default;

	Vector2 get_position_at_progress(float progress) const
	{

	}

private:
	float total_length = 0;					//计算得到的路径总长度
	std::vector<Vector2> point_list;		//存储所有顶点的位置坐标
	std::vector<float> segment_len_list;	//每两个顶点之间的路径片段长度列表
};



#endif // !_PATH_H_
