#pragma once
#ifndef _CONTROL_H
#define _CONTROL_H

#define MAX_INPUT_SIZE 1024
#define MAX_USERNAME_SIZE 128
#define MAX_PASSWORD_SIZE 128

/**
 * ��ѭ��
 */
void MAIN_LOOP();

/**
 * ��½���ѭ��
 */
void LOGIN_LOOP();

/**
 * ���������˺ŵ�½
 */
void login_control();

/**
 * �����½��˺�
 */
void signup_control();

#endif // !_CONTROL_H
