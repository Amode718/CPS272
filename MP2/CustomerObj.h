#ifndef __Customer_Obj_H__
#define __Customer_Obj_H__
#include <string>
#include <vector>
using namespace std;
class CustomerObj
{
	static int stamp;
public:
	int NO;
	int serviceTime;
	int waitStartTime;
	CustomerObj();
	friend std::ostream& operator<<(std::ostream&, const CustomerObj&);
};
#endif // !__Customer_Obj_H__