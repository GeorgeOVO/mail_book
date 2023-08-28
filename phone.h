#ifndef PHONE_H
#define PHONE_H

#define COUNT_MAX 50


typedef struct Contact
{
	char name[20];
	char sex;
	char tel[12];	
}Contact;

extern Contact* con;

void add_mail(void);
void del_mail(void);
void mod_mail(void);
void find_mail(void);
void show_mail(void);

#endif//PHONE_H
