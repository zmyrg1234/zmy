#include "control.h"
#include "user_login.h"
#include "view.h"
#include "account.h"
#include "information.h"
#include <stdbool.h>
#include <stdio.h>
int q= 0;

void MAIN_LOOP() {

	// ��½ʱ��ѭ��
	while (1) {
		char user_input[MAX_INPUT_SIZE] = { 0 };
		// ��ӡ�˵���Ϣ
		print_title();
		print_start_menu(); 

		// �����û�����
		gets(user_input);
		
		// �ж��û�����
		if (strcmp(user_input, "1") == 0) {
			// ����û�����1 ���½��û�
			signup_control();
		}
		else if (strcmp(user_input, "2") == 0) {
			// ����û�����2 ��ʹ�������ʺŵ�½
			login_control();
		}
		else if (strcmp(user_input, "3") == 0) {
			// ����û�����3 ���˳�����
			break;
		}
		else if (strcmp(user_input, "4") == 0) {
			man();
		}
		else {
			// ��ӡδʶ��Ĵ�����Ϣ
			print_error_info();
		}
	}
}

void LOGIN_LOOP(struct UserAccount user_account) {
	print_welcome();
	while (1) {
		char user_input[MAX_INPUT_SIZE] = { 0 };
		// ��ӡ�˵���Ϣ
		// @TODO: ����Ҫ�Ĺ��ܼӽ�ȥ
		print_operation_menu();

		// �����û�����
		gets(user_input);

		// �ж��û�����
		if (strcmp(user_input, "1") == 0) {
			// ����û�����1 ���½��û�
			signup_control();
		}
		else if (strcmp(user_input, "2") == 0) {
			// ����û�����2 ��ʹ�������ʺŵ�½
			login_control();
		}
		else if (strcmp(user_input, "3") == 0) {
			// ����û�����3 ���˳�����
			break;
		}
		else {
			// ��ӡδʶ��Ĵ�����Ϣ
			print_error_info();
		}
	}
}

void login_control() {
	struct UserAccount user_account;
	char username[MAX_USERNAME_SIZE] = { 0 };
	char password[MAX_PASSWORD_SIZE] = { 0 };
	bool login_sucess = false;
	printf("�������˺�:");
	gets(username);
	printf("����������:");
	gets(password);
	user_account = user_login(username, password);

	// ���num��-1���½ʧ��
	if (user_account.account.num != -1) login_sucess = true;
	else printf("��½ʧ��\n");

	if (login_sucess == false) {
		return;
	}
	else
	{
		LOGIN_LOOP(user_account);
	}
}

void signup_control() {
	struct UserAccount user_account;
	char username[MAX_USERNAME_SIZE] = { 0 };
	char password[MAX_PASSWORD_SIZE] = { 0 };
	char password_confirm[MAX_PASSWORD_SIZE] = { 0 };
	printf("�������˺�:");
	gets(username);
	printf("����������:");
	gets(password);
	printf("���ٴ���������:");
	gets(password_confirm);
	readfile();
	insert2();

	if (strcmp(password, password_confirm) == 0) {
		user_account = user_signup(username, password);
		LOGIN_LOOP(user_account);
	}
	else {
		printf("�������벻һ��!");
	}
}
