#pragma once
#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#define BASIC_SIZE 100
#define LARGE_SIZE 10000

struct User {
	char username[BASIC_SIZE]; // 用户名
	char age[BASIC_SIZE]; // 年龄
	char phone_number[BASIC_SIZE]; // 电话号码
	char gender[BASIC_SIZE]; // 性别 female or male
};

struct Account
{
	int num;
	char* content[LARGE_SIZE]; // 内容
};

struct UserAccount
{
	struct User user;
	struct Account account;
};

/**
 * 把UA数据存到本地
 */
void storeUA();


/**
 * 读取本地UA数据
 */
void readUA();

#endif // !_ACCOUNT_H
