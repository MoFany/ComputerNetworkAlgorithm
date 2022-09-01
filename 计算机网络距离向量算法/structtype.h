#pragma once
/*author:蒋明辉*/

/*用户自定义头文件*/
/*-------定义组成路由表结构体（中间加下划线的是自定义类型）-------*/

/*宏定义字符常量*/
#define Maxsize 15
#define True 1	//成立
#define False 0	//不成立

/*结构体1：定义表数据节点*/
typedef struct
{
	char dnet[Maxsize];			//目的网络
	int distance;				//距离
	char nextroute[Maxsize];	//下一跳路由
	struct list* nextdata;
}route_listdata;
/*结构体2：定义表头节点*/
typedef struct list
{
	char* headcolname1;		//目的网络表头
	char* headcolname2;		//距离表头
	char* headcolname3;		//下一跳路由表头
	route_listdata* initdatas;	//表数据，让指针变量指向它
}route_listhead;


/*结构体3：让路由器的路由表指针指向路由表*/
typedef struct list1
{
	char selfname[Maxsize];		//定义路由器的名字
	route_listhead* routelist;		//完整路由表（包含表值）
}route_type;//定义一个路由器实体


/*结构体4：由发送方路由器的拷贝产生新临时路由器*/
struct list2
{
	route_type buffersedroute;		//临时路由表
	route_type* temp;
}bufferroutelist;//结构体变量(全局变量)


//写一个结构体用于判断不同网络上路由的直接交付与间接交付情况
//拓扑结构是图，则构造一个图，即：构造一个包含两个指针区域的结构体，再将其指针域指向不同节点（路由器），
//设一个路由器有两个指针区域，用于接入不同的网络
/*
* 而网络又是一个结构体，网络结构体中没有距离的概念，网络结构体用于实现接入不同区域的路由器，
* 也就是一个网络结构体（netstruct）中又包含多个路由器（routetype）
* 不同网络之间通过某路由器进行链接
* 
* 
* typedef struct nettype
* {
*	routetype *route[Maxsize];//一个网络默认包含Maxsize个路由器数组，每个数组元素都是一个指向路由器数据类型的指针变量
*	nettype *netnext;
* }nets;
* 
* 
*/
