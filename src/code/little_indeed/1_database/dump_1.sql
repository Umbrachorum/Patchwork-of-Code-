INSERT INTO users (firstname, 
lastname, 
token_id, 
birthdate, 
email, 
password, 
premium, 
isAdmin,
isCompany,
phone_number, 
created_at, 
updated_at) 
VALUES ('Jean', 
'toto', 
'3qsfqfs2', 
'1987-07-07', 
'jean@mail.com', 
'$2y$10$OO4R/pv.V3QABjR6noFVmuHsMYmD0Iq8dsM0uOfnMPxqY7lt.KPm6', 
1, 
1,
0,
"0717567849", 
'2021-10-05 23:11:17', 
'2021-10-05 23:11:17');

INSERT INTO users (firstname, 
lastname, 
token_id, 
birthdate, 
email, 
password, 
premium, 
isAdmin,
isCompany,
phone_number, 
created_at, 
updated_at) 
VALUES ('Jean', 
'toto', 
'3qsf424qfs2', 
'1987-07-07', 
'jeanpaul@mail.com', 
'$2y$10$OO4R/pv.V3QABjR6noFVmuHsMYmD0Iq8dsM0uOfnMPxqY7lt.KPm6', 
1, 
1,
0,
"0717567849", 
'2021-10-05 23:11:17', 
'2021-10-05 23:11:17');

INSERT INTO cities (name, 
zipcode, created_at, updated_at) 
VALUES ('Lantia', 'Namalsk_city', '2021-10-05 23:11:17', '2021-10-05 23:11:17');
INSERT INTO cities (name, 
zipcode, created_at, updated_at) 
VALUES ('Vorkuta', 'Namalsk_city', '2021-10-05 23:11:17', '2021-10-05 23:11:17');
INSERT INTO cities (name, 
zipcode, created_at, updated_at) 
VALUES ('Jalovisko', 'Namalsk_city', '2021-10-05 23:11:17', '2021-10-05 23:11:17');
INSERT INTO cities (name, 
zipcode, created_at, updated_at) 
VALUES ('Lubjansk City Brother', 'Namalsk_city', '2021-10-05 23:11:17', '2021-10-05 23:11:17');

INSERT INTO parent_fields (name, created_at, 
updated_at) 
VALUES ('Industrial', '2021-10-05 23:11:17', '2021-10-05 23:11:17');
INSERT INTO parent_fields (name, created_at, 
updated_at) 
VALUES ('Computer science', '2021-10-05 23:11:17', '2021-10-05 23:11:17');
INSERT INTO parent_fields (name, created_at, 
updated_at) 
VALUES ('BTP LA', '2021-10-05 23:11:17', '2021-10-05 23:11:17');
INSERT INTO parent_fields (name, created_at, 
updated_at) 
VALUES ('Agricultural', '2021-10-05 23:11:17', '2021-10-05 23:11:17');

INSERT INTO child_fields (name, parent_fields_id, created_at, 
updated_at) 
VALUES ('Companion cube making', '1', '2021-10-05 23:11:17', '2021-10-05 23:11:17');
INSERT INTO child_fields (name, parent_fields_id, created_at, 
updated_at) 
VALUES ('GlaDos', '2', '2021-10-05 23:11:17', '2021-10-05 23:11:17');
INSERT INTO child_fields (name, parent_fields_id, created_at, 
updated_at) 
VALUES ('GreenBS', '2', '2021-10-05 23:11:17', '2021-10-05 23:11:17');

INSERT INTO companies (name, 
description, 
token_id, 
city_id, 
email, 
password, 
premium,
isCompany,  
created_at, 
updated_at) 
VALUES ('Black Mesa facility', 
'We do safe experiments about teleportation.', 
'3qsfqf545666642', 
2,
'mesa@mail.com', 
'$2y$10$OO4R/pv.V3QABjR6noFVmuHsMYmD0Iq8dsM0uOfnMPxqY7lt.KPm6', 
1,
1,
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

INSERT INTO companies (name, 
description, 
token_id, 
city_id, 
email, 
password, 
premium,
isCompany,  
created_at, 
updated_at) 
VALUES ('Aperture science', 
'We do testing.', 
'3qs12qs1545666642', 
2,
'aperture@mail.com', 
'$2y$10$OO4R/pv.V3QABjR6noFVmuHsMYmD0Iq8dsM0uOfnMPxqY7lt.KPm6', 
1,
1,
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

INSERT INTO documents (user_id,
created_at, 
updated_at) 
VALUES (2, 
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

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
VALUES ('Welcome Reclaimer', 
'dqSDAFZQSFaaAZFaaaaaaaaaaaDSLKHDFLQKSHFOZYEF KSDJKFVGZIUETRZGSCKQSBFJKAGUIGFJQVFQEZFIAHFZEFVJQSVDFHLZEUFaaaaSFSFQSFQSDZaaaaaaaaaaSDHLHLhlkchslqhfioezayfhjaaaaaaaaaaaaaaasdhvflshfzeoiysdvhlsfhopazqmmjdvhj ozh faaaaaaaaaaaaaaaacfkaGFKJGQSKDVVgfZG EFUIZOUEFGOgfgGUohojqsgfgfogkjsgfgoaaouiyaoziufoiqsdvch nozeyf zoifh zy zo zf ozhefo  heofihzeohfoe ozhf hzoehfzogoife  zhef jhf j jhjhlh fhh"oihohio ohi oiihiahohi"hohdqafg -dkfgkzg " o oizahfoi hoaih ooiehifhhzafhljhfzkjhfdjkfhazegfuegfbkjfbs', 
'3q55qsfqq6666qsf2', 
2, 
'1400', 
55, 
2,
1,
1,
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

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
VALUES ('Tester', 
"You'll test. You love testing. Meet your companion cube.", 
'3q55zzzz7777qqsf2', 
2, 
'1400', 
55, 
2,
1,
1,
'2021-09-28 14:52:35', 
'2021-09-28 14:52:35');

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
VALUES ('Tester', 
"You'll test. You love testing. Meet your companion cube.", 
'3q55zz4245qqsf2', 
2, 
'1400', 
55, 
2,
1,
2,
'2021-09-28 14:52:35', 
'2021-09-28 14:52:35');INSERT INTO jobs (title, 
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
VALUES ('Tester', 
"You'll test. You love testing. Meet your companion cube.", 
'3q55zzz5ef42sd1fqsf2', 
2, 
'1400', 
55, 
2,
1,
2,
'2021-09-28 14:52:35', 
'2021-09-28 14:52:35');INSERT INTO jobs (title, 
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
VALUES ('Tester', 
"You'll test. You love testing. Meet your companion cube.", 
'3q55z5z4f1sdfqqsf2', 
2, 
'1400', 
55, 
2,
1,
2,
'2021-09-28 14:52:35', 
'2021-09-28 14:52:35');INSERT INTO jobs (title, 
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
VALUES ('Tester', 
"You'll test. You love testing. Meet your companion cube.", 
'3q55zzzd5f4e8z7qsf2', 
2, 
'1400', 
55, 
2,
1,
1,
'2021-09-28 14:52:35', 
'2021-09-28 14:52:35');

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
VALUES ('Trolley pusher', 
'Push trolleys for science', 
'3q5554e5f5d12qqsf2', 
2, 
'1400', 
55, 
2,
3,
1,
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

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
VALUES ('Trolley pusher', 
'Push trolleys for science', 
'3q5554zz45e4f5sf2', 
2, 
'1400', 
55, 
2,
1,
1,
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

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
VALUES ('Trolley pusher', 
'Push trolleys for science', 
'3q555fzqqsf2', 
2, 
'1400', 
55, 
2,
1,
1,
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

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
VALUES ('Trolley pusher', 
'Push trolleys for science', 
'3q55544554zzqqsf2', 
2, 
'1400', 
55, 
2,
1,
1,
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

INSERT INTO job_applications (token_id, 
firstname,
lastname,
email,
phone_number,
job_id,
company_id,
message,
created_at, 
updated_at) 
VALUES ('545qsfq434sf', 
'Jean',
'Peuplu',
'JeanPeu@mail.com',
'0611734377',
2, 
2, 
'are we gamin ?',
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

INSERT INTO job_applications (token_id, 
firstname,
lastname,
email,
phone_number,
job_id,
company_id,
message,
created_at, 
updated_at) 
VALUES ('545qseerrtfqsf', 
'Jean',
'Peuplu',
'JeanPeu@mail.com',
'0611734377',
4, 
1, 
'are we gamin ?',
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

INSERT INTO job_applications (token_id, 
firstname,
lastname,
email,
phone_number,
job_id,
company_id,
message,
created_at, 
updated_at) 
VALUES ('545qsfqsf', 
'Jean',
'Peuplu',
'JeanPeu@mail.com',
'0611734377',
1, 
1, 
'are we gamin ?',
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

INSERT INTO job_applications (token_id, 
firstname,
lastname,
email,
phone_number,
job_id,
company_id,
message,
created_at, 
updated_at) 
VALUES ('545qsfzzqsf', 
'Jean',
'Peuplu',
'JeanPeu@mail.com',
'0611734377',
1, 
1, 
'are we gamin ?',
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');

INSERT INTO job_applications (token_id, 
firstname,
lastname,
email,
phone_number,
job_id,
company_id,
message,
created_at, 
updated_at) 
VALUES ('545qseffqsf', 
'Jean',
'Peuplu',
'JeanPeu@mail.com',
'0611734377',
1, 
1, 
'are we gamin ?',
'2021-09-28 14:51:35', 
'2021-09-28 14:51:35');