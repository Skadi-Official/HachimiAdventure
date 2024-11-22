#ifndef _PATH_H_
#define _PATH_H_

#include "vector2.h"

#include <vector>
/*Path���ǶԽ�ɫ�ƶ�·���ķ�װ
* ͨ������¼��·���������������ȵ�·������
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
	float total_length = 0;					//����õ���·���ܳ���
	std::vector<Vector2> point_list;		//�洢���ж����λ������
	std::vector<float> segment_len_list;	//ÿ��������֮���·��Ƭ�γ����б�
};



#endif // !_PATH_H_
