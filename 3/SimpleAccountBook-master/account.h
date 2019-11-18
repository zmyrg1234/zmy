#pragma once
#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#define BASIC_SIZE 100
#define LARG_SIZE 10000

struct User {
	char* username; // �û���
	char* age; // ����
	char* phone_number; // �绰����
	char* gender; // �Ա� female or male
};

struct Account
{
	int num;
	char* content; // ����
};

struct UserAccount
{
	User user;
	Account account;

};

void storeUA();

void readUA();

#endif // !_ACCOUNT_H
