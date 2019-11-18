#include "control.h"
#include "user_login.h"
#include "view.h"
#include <stdbool.h>
#include <stdio.h>

void MAIN_LOOP() {

	// 登陆时的循环
	while (1) {
		char user_input[MAX_INPUT_SIZE] = { 0 };
		// 打印菜单信息
		print_title();
		print_start_menu(); 

		// 接收用户输入
		gets(user_input);
		
		// 判断用户输入
		if (strcmp(user_input, "1") == 0) {
			// 如果用户输入1 则新建用户
			signup_control();
		}
		else if (strcmp(user_input, "2") == 0) {
			// 如果用户输入2 则使用已有帐号登陆
			login_control();
		}
		else if (strcmp(user_input, "3") == 0) {
			// 如果用户输入3 则退出程序
			break;
		}
		else {
			// 打印未识别的错误信息
			print_error_info();
		}
	}
}

void LOGIN_LOOP() {
	print_welcome();
	while (1) {
		char user_input[MAX_INPUT_SIZE] = { 0 };
		// 打印菜单信息
		// @TODO: 将需要的功能加进去
		print_operation_menu();

		// 接收用户输入
		gets(user_input);

		// 判断用户输入
		if (strcmp(user_input, "1") == 0) {
			// 如果用户输入1 则新建用户
			signup_control();
		}
		else if (strcmp(user_input, "2") == 0) {
			// 如果用户输入2 则使用已有帐号登陆
			login_control();
		}
		else if (strcmp(user_input, "3") == 0) {
			// 如果用户输入3 则退出程序
			break;
		}
		else {
			// 打印未识别的错误信息
			print_error_info();
		}
	}
}

void login_control() {
	char username[MAX_USERNAME_SIZE] = { 0 };
	char password[MAX_PASSWORD_SIZE] = { 0 };
	bool login_sucess = false;
	printf("请输入账号:");
	gets(username);
	printf("请输入密码:");
	gets(password);
	int success = user_login(username, password);
	if (success != -1) login_sucess = true;
	else printf("登陆失败\n");

	if (login_sucess == false) {
		return;
	}
	else
	{
		// @TODO: 登陆成功后
		LOGIN_LOOP();
	}
}

void signup_control() {
	char username[MAX_USERNAME_SIZE] = { 0 };
	char password[MAX_PASSWORD_SIZE] = { 0 };
	char password_confirm[MAX_PASSWORD_SIZE] = { 0 };
	printf("请输入账号:");
	gets(username);
	printf("请输入密码:");
	gets(password);
	printf("请再次输入密码:");
	gets(password_confirm);
}
