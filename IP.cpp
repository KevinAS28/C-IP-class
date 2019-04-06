#include <iostream>
#include <string>
#include <map>
#include <typeinfo>
#include <cmath>
template <typename any>
int index_map(any apa, std::map<int, any> pam)
{
 for (int i=0; i < pam.size(); i++)
 {
  if (apa==pam[i])
  {
   return i;
  }
 }
 throw 1;
}

std::map<int, std::string> split(std::string any, char to_split = ' ')
{
 any+=to_split;
 std::map<int, std::string> to_return;
 std::string temp0;
 int temp1 = 0;
 for (int i = 0; i < any.length(); i++)
 {
  if (any[i] == to_split)
  {
   to_return[temp1] = temp0;
   temp0 = "";
   temp1++;
   continue;
  }
  temp0 += any[i];
 }
 return to_return;
}

std::map<int, int> range(int from, int to, int step=1)
{
 std::map<int, int> to_return;
 int tanda = 0;
 for (int i = 0; i < to; i+=step)
 {
  to_return[tanda] = i;
  tanda++;
 }
 return to_return;
}
/*
class IP
{
 public:
  std::map<int, std::string> the_IP;
  std::map<int, char> IP_Class0{{0, 'A'}, {1, 'B'}, {2, 'C'}};
  char IP_Class = 'Z';
  std::map<int, int> Network;
  int Range[8];
  int BC;
  int antara[2];
  std::map<int, int>IP_Class1[3] = {range(0, 127), range(128, 191), range(192, 223)};
  IP(std::string ip, std::string slash)
  {
   //format: x.x.x.x/x
    std::map<int, std::string> IP_temp0 = split(ip, '.');
    IP_temp0[IP_temp0.size()] = slash;
    this->the_IP = IP_temp0;
  }
  char Get_Class()
  {
   for (int i = 0; i < 3; i++)
   {
    try
    {
     index_map(stoi(this->the_IP[0]), this->IP_Class1[i]);
     this->IP_Class = IP_Class0[i];
     return this->IP_Class;
    }
    catch (int e)
    {
     continue;
    }
   }
  }
  std::map<int, int> Get_Network()
  {
   int to_subs = 32;
   const int to_attent = index_map(this->IP_Class, this->IP_Class0);
   int diperhatikan = stoi(this->the_IP[to_attent]);
   int to_sum_class[] = {16, 8, 0};
   int slash = stoi(this->the_IP[4]);
   float kelipatan = pow(2, (to_subs -(slash + (to_sum_class[index_map(this->IP_Class, this->IP_Class0)]))));
   int rangeA = (floor(diperhatikan/kelipatan)+1)*kelipatan, rangeB = floor(diperhatikan/kelipatan)*kelipatan;
   std::cout << rangeA << " " << rangeB << "\n";
   std::cout << "Kelipatan: " << kelipatan << " Slash: " << slash << " diperhatikan: " << diperhatikan << "\n";
   std::map<int, int> temp1;
   for (int i = 0; i < this->the_IP.size()-2; i++)
   {
    temp1[i] = stoi(this->the_IP[i]);
   }
   temp1[to_attent] = rangeB;
   this->Network = temp1;
   return temp1;
  }
  int Get_Broadcast()
  {
   
  }
};
*/
char kelas[] = {'A', 'B', 'C'};

void print_IP(std::map<int, int> ip, int mode = 1)
{
 for (int i = 0; i < ip.size();i++)
 {
  std::cout << ip[i] << ".";
 }
 
 if (mode)
 {
  std::cout << "/"<<ip[ip.size()];
  return;
 }
 std::cout << "\n";
}

std::map<int, int> IPC(std::map<int, int> ip, int mode)
{
 int to_subs = 32;
 int &diperhatikan = (ip[3]);
 int slash = ip[4];
 int kelipatan = pow(2, (to_subs -(slash)));
 int rangeA = (floor(diperhatikan/kelipatan)+1)*kelipatan, rangeB = floor(diperhatikan/kelipatan)*kelipatan;
 switch (mode)
 {
  case 0:
   diperhatikan = rangeB;
   return ip;
  case 1:
   diperhatikan = rangeA-1;
   return ip;
  case 2:
   diperhatikan = rangeA-2;
   return ip;
  case 3:
   std::map <int, int> netmask{{0, 255}, {1, 255}, {2, 255}};
   netmask[3] = 256 - rangeA;
   return netmask;
 }
}

int main()
{ 
 std::map<int, int> test{{0, 192}, {1, 168}, {2, 2}, {3, 15}, {4, 27}};
 std::map<int, int> ip = IPC(test, 3);
 print_IP(ip, 0);

 /*
 IP ip("127.168.20.21", "28");
 std::cout << ip.Get_Class() << "\n";
 std::map <int, int> net = ip.Get_Network();
 */
}
