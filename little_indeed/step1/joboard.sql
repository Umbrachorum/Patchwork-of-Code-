/* DATABASE INIT */
DROP DATABASE IF EXISTS `joboard`;

CREATE DATABASE `joboard`;
USE `joboard`;

CREATE TABLE IF NOT EXISTS `users` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `lastname` varchar(255) NOT NULL,                      
    `firstname` varchar(255) NOT NULL,
    `birthdate` date NOT NULL,
	`email` varchar(255) NOT NULL,
	`password` varchar(255) NOT NULL,
	`token` varchar(255) NOT NULL,
	`premium` tinyint(1) NOT NULL,
	`isAdmin` tinyint(1) NOT NULL,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `companies` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(255) NOT NULL,                      
    `description` varchar(255) NOT NULL,
    `city_id` int(11) NOT NULL,
	`email` varchar(255) NOT NULL,
	`password` varchar(255) NOT NULL,
	`token` varchar(255) NOT NULL,
	`premium` tinyint(1) NOT NULL,
	`logo` MEDIUMBLOB,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `documents` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `user_id` int(11) NOT NULL,                      
    `cv` MEDIUMBLOB,
    `motivation_letter` MEDIUMBLOB,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `jobs` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
	`name` varchar(255) NOT NULL, 
    `description` varchar(255) NOT NULL,                      
    `type` varchar(255) NOT NULL,
    `salary` varchar(255) NOT NULL,
	`worktime` int(11) NOT NULL,
	`parent_fields_id` int(11) NOT NULL,
	`child_fields_id` int(11) NOT NULL,
	`company_id` int(11) NOT NULL,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `job_applications` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
	`user_id` int(11) NOT NULL, 
    `job_id` int(11) NOT NULL,
	`company_id` int(11) NOT NULL,
	`message` varchar(255) NOT NULL,
	`cv` MEDIUMBLOB,
	`motivation_letter` MEDIUMBLOB,
	`created_at` datetime NOT NULL,
	`updated_at` datetime NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `cities` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
	`city` varchar(255) NOT NULL,
	`zipcode` varchar(255) NOT NULL,
    
    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `parent_fields` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(255) NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS `child_fields` (
    `id` int(11) NOT NULL AUTO_INCREMENT,
    `name` varchar(255) NOT NULL,
	`parent_id` int(11) NOT NULL,

    PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/* MESSAGES TESTS */
-- INSERT INTO messages (name, message, date) 
-- VALUES ('Gordon', 'Hoy mate', '2017-07-21 17:17:21');

-- INSERT INTO messages (name, message, date) 
-- VALUES ('Gordon', 'Hoy mate', '2017-07-21 17:18:21');

-- INSERT INTO messages (name, message, date) 
-- VALUES ('Gordon', 'Hoy mate', '2017-07-21 17:19:21');

-- INSERT INTO messages (name, message, date) 
-- VALUES ('Gordon', 'Hoy mate', '2017-07-21 17:20:21');

-- INSERT INTO messages (name, message, date) 
-- VALUES ('Gordon', 'Hoy mate', '2017-07-21 17:21:21');