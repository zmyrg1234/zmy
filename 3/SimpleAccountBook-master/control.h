#pragma once
#ifndef _CONTROL_H
#define _CONTROL_H

#define MAX_INPUT_SIZE 1024
#define MAX_USERNAME_SIZE 128
#define MAX_PASSWORD_SIZE 128

/**
 * 主循环
 */
void MAIN_LOOP();

/**
 * 登陆后的循环
 */
void LOGIN_LOOP();

/**
 * 控制已有账号登陆
 */
void login_control();

/**
 * 控制新建账号
 */
void signup_control();

#endif // !_CONTROL_H
