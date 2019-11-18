#pragma once
#ifndef _ACCOUNT_H
#define _ACCOUNT_H

#define BASIC_SIZE 100
#define LARGE_SIZE 10000

struct User {
	char username[BASIC_SIZE]; // �û���
	char age[BASIC_SIZE]; // ����
	char phone_number[BASIC_SIZE]; // �绰����
	char gender[BASIC_SIZE]; // �Ա� female or male
};

struct Account
{
	int num;
	char* content[LARGE_SIZE]; // ����
};

struct UserAccount
{
	struct User user;
	struct Account account;
};

/**
 * ��UA���ݴ浽����
 */
void storeUA();


/**
 * ��ȡ����UA����
 */
void readUA();

#endif // !_ACCOUNT_H
