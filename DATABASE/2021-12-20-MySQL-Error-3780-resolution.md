---
layout: post
title: "MySQL-Error 3780 resolution"
date: 2021-12-07 12:07:57 +0900
categories: DB
---

# Error 3780

Referencing column `userid` and referenced column `userid` in foreign key constraint `team_info_to_member_fk` are incompatible.

I had this error for like an hour or so. I tried almost everything, but nothing worked. However, the resolution was recklessly simple.

## Foreign key

Working with teammates was a fantastic experience, but it was the primary cause of this issue.

### User Table

My sources were not up-to-date since I committed a few things and did not want to push them yet. Thus, the DB code was sent via discord, missing the `default charset` and `collate` settings. Unfortunately, our default setting did not match.

```sql
DROP TABLE IF EXISTS `user`;
create table user (
  userid varchar(16) NOT NULL,
  userpwd varchar(30) NOT NULL,
  username varchar(10) NOT NULL,
  email varchar(50) NOT NULL,
  regdate timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  auth char(1) DEFAULT 'N',
  mbti varchar(12) DEFAULT NULL,
  usertype varchar(10) DEFAULT NULL,
  report varchar(10) DEFAULT NULL,
  PRIMARY KEY (userid)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
```

### Team Info Table

And here is my code...
When I was missing Engine query and set my table to charset utf8, **it caused an error**
It was saying, `excuse me, int and varchar ain't same..` tho I was referencing varchar(16)...

```sql
CREATE TABLE `teaminfo`(
  teamno int NOT NULL AUTO_INCREMENT,
  userid varchar(16) DEFAULT NULL,
  subject varchar(100) DEFAULT NULL,
  content varchar(3000) DEFAULT NULL,
  regtime timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `C/C++` tinyint null default 0,
  Java tinyint null default 0,
  Python tinyint null default 0,
  Spring tinyint null default 0,
  `Vue.js` tinyint null default 0,
  `React.js` tinyint null default 0,
  swift tinyint null default 0,
  android  tinyint null default 0,
  PRIMARY KEY (`teamno`),
  KEY `teaminfo_to_member_fk` (`userid`),
  CONSTRAINT `teaminfo_to_member_fk` FOREIGN KEY (`userid`) REFERENCES `user` (`userid`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

```

THE PROBLEM WAS SOLVED when both charset and collate query were set to both user and team info tables.

## Other possible issues

In order to solve error 3780,
there are a few more possibilities that it might be causing the error.

1. unsigned int
2. Unicode
3. referencing different types (varchar vs. int ..., int(6) vs. int)
4. AI
5. Foreign key needs to be set to PK or Unique
