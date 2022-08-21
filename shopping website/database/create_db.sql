DROP DATABASE IF EXISTS `webfp`;
CREATE DATABASE `webfp`; 
USE `webfp`;

SET NAMES utf8 ;
SET character_set_client = utf8mb4 ;

CREATE TABLE `orders` (
  `order_id` int(11) NOT NULL AUTO_INCREMENT,
  `member_id` int(11) NOT NULL,
  `product_name` varchar(50)  NOT NULL,
  `amount` int(11) NOT NULL,
  `total_price` int(11) NOT NULL,
  PRIMARY KEY (`order_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
INSERT INTO `orders` VALUES (1,1,'犬用蚤不到滴劑',2, 1900);
INSERT INTO `orders` VALUES (2,2,'貓用化毛膏', 1, 1160);
INSERT INTO `orders` VALUES (3,2,'法國皇家成貓飼料', 3, 5940);
INSERT INTO `orders` VALUES (4,2,'希爾斯成貓飼料', 1, 2420);
INSERT INTO `orders` VALUES (5,1,'寵物牽繩', 10, 3000);
INSERT INTO `orders` VALUES (6,1,'貓跳台1', 2, 9300);
INSERT INTO `orders` VALUES (7,1,'法國皇家飽足犬飼料', 1, 2420);
INSERT INTO `orders` VALUES (8,1,'貓用蚤不到滴劑', 4, 3400);
INSERT INTO `orders` VALUES (9,2,'Ever Clean 礦物砂', 2, 1100);
INSERT INTO `orders` VALUES (10,1,'戶外防水狗屋2', 1, 6550);

CREATE TABLE `members` (
  `member_id` int(11) NOT NULL,
  `name` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL,
  `phone` varchar(50) NOT NULL,
  `points` int(11) NOT NULL,
  PRIMARY KEY (`member_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
INSERT INTO `members` VALUES (1,'misvip', 'mis888','0934-535-453',8090);
INSERT INTO `members` VALUES (2,'misuser', 'mis666','0935-576-223', 777);

CREATE TABLE `products` (
  `product_name` varchar(50) NOT NULL,
  `product_type` varchar(50) NOT NULL,
  `price` int(11) NOT NULL,
  PRIMARY KEY (`product_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
INSERT INTO `products` VALUES ('法國皇家成貓飼料','進口飼料',1980);
INSERT INTO `products` VALUES ('法國皇家腸胃敏感貓飼料國皇家成貓飼料','進口飼料',2320);
INSERT INTO `products` VALUES ('法國皇家水解低敏配方','進口飼料',2320);
INSERT INTO `products` VALUES ('希爾斯成貓飼料','進口飼料',2420);
INSERT INTO `products` VALUES ('希爾斯7歲以上成貓飼料','進口飼料',2330);
INSERT INTO `products` VALUES ('希爾斯腸胃敏感貓飼料','進口飼料',2320);
INSERT INTO `products` VALUES ('法國皇家成犬飼料','進口飼料',2520);
INSERT INTO `products` VALUES ('法國皇家飽足犬飼料','進口飼料',2420);
INSERT INTO `products` VALUES ('法國皇家皮膚保養犬飼料','進口飼料',2880);
INSERT INTO `products` VALUES ('希爾斯幼犬飼料','進口飼料',1880);
INSERT INTO `products` VALUES ('希爾斯7歲以上成犬飼料','進口飼料',2330);
INSERT INTO `products` VALUES ('希爾斯成犬飼料','進口飼料',1980);
INSERT INTO `products` VALUES ('法國皇家犬貓營養罐頭','罐頭保健',350);
INSERT INTO `products` VALUES ('法國皇家幼貓罐頭','罐頭保健',750);
INSERT INTO `products` VALUES ('西莎犬罐頭 蒔蘿焗烤菲力牛','罐頭保健',60);
INSERT INTO `products` VALUES ('犬關節營養素','罐頭保健',1980);
INSERT INTO `products` VALUES ('犬修復關節咀嚼片','罐頭保健',2250);
INSERT INTO `products` VALUES ('貓用促進食慾膏 鰹魚口味','罐頭保健',760);
INSERT INTO `products` VALUES ('貓用化毛膏','罐頭保健',1160);
INSERT INTO `products` VALUES ('貓用蚤不到滴劑','除蟲藥劑',850);
INSERT INTO `products` VALUES ('犬用蚤不到滴劑','除蟲藥劑',950);
INSERT INTO `products` VALUES ('犬貓用蚤不到噴劑','除蟲藥劑',1150);
INSERT INTO `products` VALUES ('犬用口服心絲蟲藥','除蟲藥劑',1440);
INSERT INTO `products` VALUES ('犬用除心絲蟲藥滴劑','除蟲藥劑',1170);
INSERT INTO `products` VALUES ('日本製貓砂盆','清潔美容',1150);
INSERT INTO `products` VALUES ('日本製圓形貓砂盆','清潔美容',1450);
INSERT INTO `products` VALUES ('Cats Best 木屑砂','清潔美容',950);
INSERT INTO `products` VALUES ('Ever Clean 礦物砂','清潔美容',550);
INSERT INTO `products` VALUES ('天然有機寵物清潔劑','清潔美容',750);
INSERT INTO `products` VALUES ('可充電剃剪','清潔美容',1280);
INSERT INTO `products` VALUES ('日本製寵物指甲剪 大','清潔美容',1550);
INSERT INTO `products` VALUES ('日本製寵物指甲剪 小(兩色)','清潔美容',950);
INSERT INTO `products` VALUES ('犬用胸背袋','外出用品',530);
INSERT INTO `products` VALUES ('寵物牽繩','外出用品',330);
INSERT INTO `products` VALUES ('寵物牽繩(兩色)','外出用品',450);
INSERT INTO `products` VALUES ('寵物提籠','外出用品',1050);
INSERT INTO `products` VALUES ('寵物提籠(圓)','外出用品',1550);
INSERT INTO `products` VALUES ('日本製寵物推車','外出用品',3580);
INSERT INTO `products` VALUES ('美國製寵物推車','外出用品',3220);
INSERT INTO `products` VALUES ('貓用睡窩1','居家用品',650);
INSERT INTO `products` VALUES ('貓用睡窩2','居家用品',720);
INSERT INTO `products` VALUES ('直立式貓抓板','居家用品',820);
INSERT INTO `products` VALUES ('貓抓板睡盆','居家用品',1220);
INSERT INTO `products` VALUES ('貓跳台1','居家用品',4650);
INSERT INTO `products` VALUES ('貓跳台2','居家用品',3250);
INSERT INTO `products` VALUES ('小型犬用睡窩','居家用品',980);
INSERT INTO `products` VALUES ('戶外防水狗屋1','居家用品',3980);
INSERT INTO `products` VALUES ('戶外防水狗屋2','居家用品',6550);

-- CREATE TABLE `photos` (
--   `member_id` int(11) NOT NULL,
--   `name` varchar(50) NOT NULL,
--   `member_photo` longblob DEFAULT NULL,
--   PRIMARY KEY (`member_id`)
-- ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
-- INSERT INTO `photos` VALUES (1, 'misvip', LOAD_FILE('C:/xampp/htdocs/shopping website/images/member_photos/dog_photo.jpg'));

CREATE TABLE `photos` (
  `member_id` int(11) NOT NULL ,
  `member_photo` varchar(200) NOT NULL,
  `text` text,
  PRIMARY KEY (`member_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;