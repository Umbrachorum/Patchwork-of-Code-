/* DATABASE INIT */
DROP DATABASE IF EXISTS `joboard`;

CREATE DATABASE `joboard`;
USE `joboard`;

CREATE TABLE IF NOT EXISTS `users` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
	`token_id` varchar(255) NOT NULL default "",
    `lastname` varchar(255) NOT NULL,
    `firstname` varchar(255) NOT NULL,
    `birthdate` date NOT NULL,
	`email` varchar(255) NOT NULL,
	`password` varchar(255) NOT NULL,
	`premium` tinyint(1) NOT NULL,
	`isAdmin` tinyint(1) NOT NULL,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO users (firstname, 
lastname, 
token_id, 
birthdate, 
email, 
password, 
premium, 
isAdmin, 
created_at, 
updated_at) 
VALUES ('Jean', 
'toto', 
'3qsfqfs2', 
'1987-07-07', 
'jean@mail.com', 
'toto', 
'1', 
'1', 
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

CREATE TABLE IF NOT EXISTS `cities` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
	`city` varchar(255) NOT NULL,
	`zipcode` varchar(255) NOT NULL,
    
    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO cities (city, 
zipcode) 
VALUES ('Lantia', 'Namalsk_city');
INSERT INTO cities (city, 
zipcode) 
VALUES ('Vorkuta', 'Namalsk_city');
INSERT INTO cities (city, 
zipcode) 
VALUES ('Jalovisko', 'Namalsk_city');

CREATE TABLE IF NOT EXISTS `parent_fields` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(255) NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO parent_fields (name) 
VALUES ('Industrial');
INSERT INTO parent_fields (name) 
VALUES ('Computer science');
INSERT INTO parent_fields (name) 
VALUES ('BTP LA');
INSERT INTO parent_fields (name) 
VALUES ('Agricultural');

CREATE TABLE IF NOT EXISTS `child_fields` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(255) NOT NULL,
	`parent_id` int(11) NOT NULL,

    PRIMARY KEY (`id`),
	FOREIGN KEY (`parent_id`) REFERENCES parent_fields(`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO child_fields (name, parent_id) 
VALUES ('Companion cube making', '1');
INSERT INTO child_fields (name, parent_id) 
VALUES ('GlaDos', '2');
INSERT INTO child_fields (name, parent_id) 
VALUES ('Dynamic walls', '3');

CREATE TABLE IF NOT EXISTS `companies` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
	`token_id` varchar(255) NOT NULL default "",
    `name` varchar(255) NOT NULL,
    `description` varchar(255) NOT NULL,
    `city_id` int(11) NOT NULL,
	`email` varchar(255) NOT NULL,
	`password` varchar(255) NOT NULL,
	`premium` tinyint(1) NOT NULL,
	`logo` MEDIUMBLOB,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`),
	FOREIGN KEY (`city_id`) REFERENCES cities(`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO companies (name, 
description, 
token_id, 
city_id, 
email, 
password, 
premium,  
created_at, 
updated_at) 
VALUES ('Jean', 
'toto', 
'3qsfqfs2', 
2, 
'jean_comp@mail.com', 
'toto', 
1,
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

CREATE TABLE IF NOT EXISTS `documents` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `user_id` int(11) NOT NULL,                      
    `cv` MEDIUMBLOB,
    `motivation_letter` MEDIUMBLOB,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`),
	FOREIGN KEY (`user_id`) REFERENCES users(`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO documents (user_id,
created_at, 
updated_at) 
VALUES (1, 
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

CREATE TABLE IF NOT EXISTS `jobs` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
	`token_id` varchar(255) NOT NULL default "",
	`title` varchar(255) NOT NULL, 
    `description` varchar(255) NOT NULL,                      
    `salary` varchar(255) NOT NULL,
	`worktime` int(11) NOT NULL,
	`city_id` int(11) NOT NULL,
	`parent_fields_id` int(11) NOT NULL,
	`child_fields_id` int(11) NOT NULL,
	`company_id` int(11) NOT NULL,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`),
	FOREIGN KEY (`city_id`) REFERENCES cities(`id`),
	FOREIGN KEY (`parent_fields_id`) REFERENCES parent_fields(`id`),
	FOREIGN KEY (`child_fields_id`) REFERENCES child_fields(`id`),
	FOREIGN KEY (`company_id`) REFERENCES companies(`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO jobs (title, 
description, 
token_id, 
city_id, 
salary, 
worktime, 
parent_fields_id,
child_fields_id,
company_id,
created_at, 
updated_at) 
VALUES ('We gamer', 
'we gaming', 
'3q55qqsf2', 
2, 
'1400', 
55, 
2,
1,
1,
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

CREATE TABLE IF NOT EXISTS `job_applications` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
	`token_id` varchar(255) NOT NULL default "",
	`user_id` int(11) NOT NULL, 
    `job_id` int(11) NOT NULL,
	`company_id` int(11) NOT NULL,
	`message` varchar(255) NOT NULL,
	`cv` MEDIUMBLOB,
	`motivation_letter` MEDIUMBLOB,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`),
	FOREIGN KEY (`user_id`) REFERENCES users(`id`),
	FOREIGN KEY (`job_id`) REFERENCES jobs(`id`),
	FOREIGN KEY (`company_id`) REFERENCES companies(`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO job_applications (token_id, 
user_id,
job_id,
company_id,
message,
created_at, 
updated_at) 
VALUES ('545qsfqsf', 
1, 
1, 
1, 
'are we gamin ?',
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');


/* TESTS */


-- INSERT INTO jobs (title, description, city_id, salary, worktime, parent_fields_id, child_fields_id, company_id, created_at, updated_at) 
-- VALUES ('Web bricouleur', 'on fait el bricoulage', '3', '0,00', '35', '1', '1', '3', '2021-09-28 14:51:35', '2021-09-28 14:51:35');

