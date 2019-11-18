#pragma once
#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#define BASIC_SIZE 100
#define LARG_SIZE 10000

struct User {
	char* username; // 用户名
	char* age; // 年龄
	char* phone_number; // 电话号码
	char* gender; // 性别 female or male
};

struct Account
{
	int num;
	char* content; // 内容
};

struct UserAccount
{
	User user;
	Account account;

};

void storeUA();

void readUA();

#endif // !_ACCOUNT_H
