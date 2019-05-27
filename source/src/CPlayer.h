#include <sampgdk.h>
#include <string>

using namespace std;

class CPlayer
{
public:
	bool Connect(int playerid);
	bool Disconnect(int playerid, int reason);

	string Name;
private:

};