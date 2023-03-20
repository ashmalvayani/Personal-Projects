-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 21, 2021 at 02:59 AM
-- Server version: 10.4.21-MariaDB
-- PHP Version: 7.3.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `foodpanda`
--

-- --------------------------------------------------------

--
-- Table structure for table `address`
--

CREATE TABLE `address` (
  `address_id` int(11) NOT NULL,
  `cus_id` int(11) DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `city` varchar(10) DEFAULT NULL,
  `zipcode` int(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `address`
--

INSERT INTO `address` (`address_id`, `cus_id`, `address`, `city`, `zipcode`) VALUES
(11, 6, 'B#08 Silver Appartments Opp FAST, Sindh', 'Karachi', 75104),
(35, 2, 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', 'Karachi', 74550);

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `admin_id` int(11) NOT NULL,
  `rev_id` int(11) DEFAULT NULL,
  `res_id` int(11) DEFAULT NULL,
  `order_id` int(11) DEFAULT NULL,
  `rider_id` int(11) DEFAULT NULL,
  `bill_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `billing`
--

CREATE TABLE `billing` (
  `bill_id` int(11) NOT NULL,
  `cus_id` int(11) DEFAULT NULL,
  `order_id` int(11) DEFAULT NULL,
  `rider_id` int(11) DEFAULT NULL,
  `payment_method` varchar(20) DEFAULT NULL,
  `Address` varchar(100) DEFAULT NULL,
  `PostCode` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `billing`
--

INSERT INTO `billing` (`bill_id`, `cus_id`, `order_id`, `rider_id`, `payment_method`, `Address`, `PostCode`) VALUES
(30, 2, 15, 6, 'Credit / Debit Card', 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', '74550'),
(31, 2, 16, 3, 'Cash on Delivery', 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', '74550'),
(32, 6, 19, 2, 'Credit / Debit Card', 'B#08 Silver Appartments Opp FAST, Sindh', '75104'),
(33, 2, 24, 3, 'Cash on Delivery', 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', '74550'),
(34, 2, 25, 6, 'Credit / Debit Card', 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', '74550'),
(37, 2, 26, 6, 'Cash on Delivery', 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', '74550'),
(40, 2, 27, 5, 'Cash on Delivery', 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', '74550'),
(52, 2, 29, 4, 'Cash on Delivery', 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', '74550'),
(53, 2, 30, 1, 'Cash on Delivery', 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', '74550'),
(54, 2, 31, 4, 'Credit / Debit Card', 'Real Housing Society, Apt no. 6, Abraham Street, Garden East, Near Big bite, Karachi.', '74550');

-- --------------------------------------------------------

--
-- Table structure for table `category`
--

CREATE TABLE `category` (
  `category_id` int(11) NOT NULL,
  `category_name` varchar(20) NOT NULL,
  `image_url` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `category`
--

INSERT INTO `category` (`category_id`, `category_name`, `image_url`) VALUES
(1, 'ITALIAN', 'italian.jpg'),
(2, 'CHINESE', 'chinese.webp'),
(3, 'FAST FOOD', 'fast food.webp'),
(4, 'BBQ', 'bbq.webp'),
(5, 'BEVERAGES', 'beverages.webp'),
(6, 'DESSERTS', 'dessert.webp');

-- --------------------------------------------------------

--
-- Table structure for table `creditcardinfo`
--

CREATE TABLE `creditcardinfo` (
  `s_no` int(11) NOT NULL,
  `card_num` varchar(20) DEFAULT NULL,
  `cus_id` int(11) DEFAULT NULL,
  `card_expire` date DEFAULT NULL,
  `cvc` int(3) DEFAULT NULL,
  `card_holder_name` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `creditcardinfo`
--

INSERT INTO `creditcardinfo` (`s_no`, `card_num`, `cus_id`, `card_expire`, `cvc`, `card_holder_name`) VALUES
(4, '4266841412311231', 2, '2021-11-16', 123, 'Hasnain Somani'),
(13, '1123123123123', 6, '0000-00-00', 765, 'Hammad Shakir'),
(14, '123123123', 2, '2021-12-31', 123, 'Ashmal Anis'),
(15, '13123123123', 2, '2022-11-19', 456, 'Ashmal Anis'),
(16, '43545345', 2, '2024-10-20', 789, 'Hammad Shakir');

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `cus_id` int(11) NOT NULL,
  `cus_name` varchar(20) NOT NULL,
  `cus_phone` varchar(13) DEFAULT NULL,
  `cus_email` varchar(30) DEFAULT NULL,
  `cus_pass` varchar(20) NOT NULL,
  `premium` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`cus_id`, `cus_name`, `cus_phone`, `cus_email`, `cus_pass`, `premium`) VALUES
(1, 'samad', '03219275608', 'samad@gmail.com', 'samad', 0),
(2, 'ashmal', '03310381899', 'ashmal@gmail.com', 'ashmal', 20),
(3, 'hasnain', '03313594605', 'hasnain@gmail.com', 'hasnain', 50),
(4, 'sam', '021343909415', 'abdul@gmail.com', 'ashmal', 10),
(5, 'adnan', '+923040880308', 'adnan@gmail.com', 'adnan', 0),
(6, 'Hammad', '021343909415', 'hammad@gmail.com', 'hammad', 20);

-- --------------------------------------------------------

--
-- Table structure for table `food`
--

CREATE TABLE `food` (
  `food_id` int(11) NOT NULL,
  `food_name` varchar(20) DEFAULT NULL,
  `food_price` int(11) DEFAULT NULL,
  `category_id` int(11) DEFAULT NULL,
  `res_id` int(11) DEFAULT NULL,
  `image_url` varchar(200) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `food`
--

INSERT INTO `food` (`food_id`, `food_name`, `food_price`, `category_id`, `res_id`, `image_url`) VALUES
(1, 'ALFREDO PASTA', 950, 1, 1, 'ITALIAN/Food/Bella Vita/alfredopasta.webp'),
(2, 'BEEF LASAGNA', 1400, 1, 1, 'ITALIAN/Food/Bella Vita/beeflasagna.jpg'),
(3, 'CALZONE', 1000, 1, 1, 'ITALIAN/Food/Bella Vita/calzone.jpg'),
(4, 'CHICKEN LASAGNA', 1100, 1, 1, 'ITALIAN/Food/Bella Vita/Focaccia.webp'),
(5, 'Focaccia', 800, 1, 1, 'ITALIAN/Food/Bella Vita/lasagna.webp'),
(6, 'PIZZA LARGE', 1200, 1, 1, 'ITALIAN/Food/Bella Vita/pasta.jpg'),
(7, 'SPECIAL PASTA', 1100, 1, 1, 'ITALIAN/Food/Bella Vita/pizza.jpg'),
(8, 'PIZZA MEDIUM', 800, 1, 1, 'ITALIAN/Food/Bella Vita/raviolli.webp'),
(9, 'PIZZA SMALL', 300, 1, 1, 'ITALIAN/Food/Bella Vita/regularpizza.jpg'),
(10, 'Spaghetti', 450, 1, 1, 'ITALIAN/Food/Bella Vita/smallpizza.jpg'),
(11, 'STEAK', 1550, 1, 1, 'ITALIAN/Food/Bella Vita/spaghetti.jpg'),
(12, 'Stuffed Ravioli', 750, 1, 1, 'ITALIAN/Food/Bella Vita/steak.jpg'),
(13, 'ALFREDO PASTA', 950, 1, 2, 'ITALIAN/Food/Delfrio/alfredo pasta.jpg'),
(14, 'BEEF LASAGNA', 1400, 1, 2, 'ITALIAN/Food/Delfrio/beef lasagna.jpg'),
(15, 'CALZONE', 1000, 1, 2, 'ITALIAN/Food/Delfrio/calzone.jpg'),
(16, 'CHICKEN LASAGNA', 1100, 1, 2, 'ITALIAN/Food/Delfrio/CHICKEN LASAGNA.jpg'),
(17, 'Focaccia', 800, 1, 2, 'ITALIAN/Food/Delfrio/Focaccia.jpg'),
(18, 'PIZZA LARGE', 1200, 1, 2, 'ITALIAN/Food/Delfrio/large pizza.jpg'),
(19, 'SPECIAL PASTA', 1100, 1, 2, 'ITALIAN/Food/Delfrio/pasta.webp'),
(20, 'PIZZA MEDIUM', 800, 1, 2, 'ITALIAN/Food/Delfrio/regular pizza.jpg'),
(21, 'PIZZA SMALL', 300, 1, 2, 'ITALIAN/Food/Delfrio/small pizza.jpg'),
(22, 'Spaghetti', 450, 1, 2, 'ITALIAN/Food/Delfrio/Spaghetti.jpg'),
(23, 'STEAK', 1550, 1, 2, 'ITALIAN/Food/Delfrio/STEAK.jpg'),
(24, 'Stuffed Ravioli', 750, 1, 2, 'ITALIAN/Food/Delfrio/Stuffed Ravioli.jpg'),
(25, 'ALFREDO PASTA', 950, 1, 3, 'ITALIAN/Food/The hot spot/alfredo pasta.webp'),
(26, 'BEEF LASAGNA', 1400, 1, 3, 'ITALIAN/Food/The hot spot/beef lasagna.jpg'),
(27, 'CALZONE', 1000, 1, 3, 'ITALIAN/Food/The hot spot/calzone.jpg'),
(28, 'CHICKEN LASAGNA', 1100, 1, 3, 'ITALIAN/Food/The hot spot/CHICKEN LASAGNA.jpg'),
(29, 'Focaccia', 800, 1, 3, 'ITALIAN/Food/The hot spot/Focaccia.jpg'),
(30, 'PIZZA LARGE', 1200, 1, 3, 'ITALIAN/Food/The hot spot/large pizza.jpg'),
(31, 'SPECIAL PASTA', 1100, 1, 3, 'ITALIAN/Food/The hot spot/pasta.webp'),
(32, 'PIZZA MEDIUM', 800, 1, 3, 'ITALIAN/Food/The hot spot/regular pizza.jpg'),
(33, 'PIZZA SMALL', 300, 1, 3, 'ITALIAN/Food/The hot spot/small pizza.jpg'),
(34, 'Spaghetti', 450, 1, 3, 'ITALIAN/Food/The hot spot/Spaghetti.webp'),
(35, 'STEAK', 1550, 1, 3, 'ITALIAN/Food/The hot spot/STEAK.jpg'),
(36, 'Stuffed Ravioli', 750, 1, 3, 'ITALIAN/Food/The hot spot/Stuffed Ravioli.jpg'),
(37, 'ALFREDO PASTA', 950, 1, 4, 'ITALIAN/Food/Pizza Hut/alfredo pasta.jpg'),
(38, 'BEEF LASAGNA', 1400, 1, 4, 'ITALIAN/Food/Pizza Hut/beef lasagna.jpg'),
(39, 'CALZONE', 1000, 1, 4, 'ITALIAN/Food/Pizza Hut/calzone.jpg'),
(40, 'CHICKEN LASAGNA', 1100, 1, 4, 'ITALIAN/Food/Pizza Hut/CHICKEN LASAGNA.jpg'),
(41, 'Focaccia', 800, 1, 4, 'ITALIAN/Food/Pizza Hut/Focaccia.jpg'),
(42, 'PIZZA LARGE', 1200, 1, 4, 'ITALIAN/Food/Pizza Hut/large pizza.jpg'),
(43, 'SPECIAL PASTA', 1100, 1, 4, 'ITALIAN/Food/Pizza Hut/pasta.webp'),
(44, 'PIZZA MEDIUM', 800, 1, 4, 'ITALIAN/Food/Pizza Hut/regular pizza.jpg'),
(45, 'PIZZA SMALL', 300, 1, 4, 'ITALIAN/Food/Pizza Hut/small pizza.jpg'),
(46, 'Spaghetti', 450, 1, 4, 'ITALIAN/Food/Pizza Hut/Spaghetti.jpg'),
(47, 'STEAK', 1550, 1, 4, 'ITALIAN/Food/Pizza Hut/STEAK.jpg'),
(48, 'Stuffed Ravioli', 750, 1, 4, 'ITALIAN/Food/Pizza Hut/Stuffed Ravioli.jpg'),
(49, 'BEEF CHOWMEIN', 650, 2, 5, 'CHINESE/FOOD/Ginsoy/beef chowmein.jpg'),
(50, 'CHICKEN CHOWMEIN', 450, 2, 5, 'CHINESE/FOOD/Ginsoy/chicken chowmein.jpg'),
(51, 'CHICKEN FRIED RICE', 850, 2, 5, 'CHINESE/FOOD/Ginsoy/CHICKEN FRIED RICE.jpg'),
(52, 'CHICKEN SHASHLIK WIT', 800, 2, 5, 'CHINESE/FOOD/Ginsoy/CHICKEN SHASHLIK WITH RICE.jpg'),
(53, ' Dumplings (12 pcs)', 500, 2, 5, 'CHINESE/FOOD/Ginsoy/Dumplings.jpg'),
(54, 'Hot Pot', 600, 2, 5, 'CHINESE/FOOD/Ginsoy/Hot Pot.jpg'),
(55, 'Kung Pao Chicken', 850, 2, 5, 'CHINESE/FOOD/Ginsoy/Kung Pao Chicken.jpg'),
(56, 'MANCHURIAN', 800, 2, 5, 'CHINESE/FOOD/Ginsoy/MANCHURIAN.jpg'),
(57, 'Peking Roasted Duck', 1000, 2, 5, 'CHINESE/FOOD/Ginsoy/Peking Roasted Duck.jpg'),
(58, ' Scrambled Eggs with', 600, 2, 5, 'CHINESE/FOOD/Ginsoy/Scrambled Eggs with Tomatoes.jpg'),
(59, 'Shrimp with Vermicel', 650, 2, 5, 'CHINESE/FOOD/Ginsoy/Shrimp with Vermicelli and Garlic.jpg'),
(60, 'SPRING ROLL (12 pcs)', 300, 2, 5, 'CHINESE/FOOD/Ginsoy/SPRING ROLL.jpg'),
(61, 'Wontons (12 pcs)', 600, 2, 5, 'CHINESE/FOOD/Ginsoy/Wontons.jpg'),
(62, 'Yangzhou Fried Rice', 850, 2, 5, 'CHINESE/FOOD/Ginsoy/Yangzhou Fried Rice.jpg'),
(63, 'BEEF CHOWMEIN', 650, 2, 7, 'CHINESE/FOOD/tao/beef chowmein.jpg'),
(64, 'BEEF CHOWMEIN', 650, 2, 6, 'CHINESE/FOOD/xian/beef chowmein.jpg'),
(65, 'CHICKEN CHOWMEIN', 450, 2, 6, 'CHINESE/FOOD/xian/chicken chowmein.jpg'),
(66, 'CHICKEN FRIED RICE', 850, 2, 6, 'CHINESE/FOOD/xian/CHICKEN FRIED RICE.jpg'),
(67, 'CHICKEN SHASHLIK WIT', 800, 2, 6, 'CHINESE/FOOD/xian/CHICKEN SHASHLIK WITH RICE.jpeg'),
(68, ' Dumplings (12 pcs)', 500, 2, 6, 'CHINESE/FOOD/xian/Dumplings.jpg'),
(69, 'Hot Pot', 600, 2, 6, 'CHINESE/FOOD/xian/Hot Pot.jpg'),
(70, 'Kung Pao Chicken', 850, 2, 6, 'CHINESE/FOOD/xian/Kung Pao Chicken.jpg'),
(71, 'MANCHURIAN', 800, 2, 6, 'CHINESE/FOOD/xian/MANCHURIAN.jpg'),
(72, 'Peking Roasted Duck', 1000, 2, 6, 'CHINESE/FOOD/xian/Peking Roasted Duck.jpg'),
(73, ' Scrambled Eggs with', 600, 2, 6, 'CHINESE/FOOD/xian/Scrambled Eggs with Tomatoes.jpg'),
(74, 'Shrimp with Vermicel', 650, 2, 6, 'CHINESE/FOOD/xian/Shrimp with Vermicelli and Garlic.jpg'),
(75, 'SPRING ROLL (12 pcs)', 300, 2, 6, 'CHINESE/FOOD/xian/SPRING ROLL.jpg'),
(76, 'Wontons (12 pcs)', 600, 2, 6, 'CHINESE/FOOD/xian/Wontons.jpg'),
(77, 'Yangzhou Fried Rice', 850, 2, 6, 'CHINESE/FOOD/xian/Yangzhou Fried Rice.webp'),
(78, 'CHICKEN FRIED RICE', 850, 2, 7, 'CHINESE/FOOD/tao/CHICKEN FRIED RICE.jpg'),
(79, 'CHICKEN SHASHLIK WIT', 800, 2, 7, 'CHINESE/FOOD/tao/CHICKEN SHASHLIK WITH RICE.jpeg'),
(80, ' Dumplings (12 pcs)', 500, 2, 7, 'CHINESE/FOOD/tao/Dumplings.jpg'),
(81, 'Hot Pot', 600, 2, 7, 'CHINESE/FOOD/tao/Hot Pot.jpg'),
(82, 'Kung Pao Chicken', 850, 2, 7, 'CHINESE/FOOD/tao/Kung Pao Chicken.jpg'),
(83, 'MANCHURIAN', 800, 2, 7, 'CHINESE/FOOD/tao/MANCHURIAN.jpg'),
(84, 'Peking Roasted Duck', 1000, 2, 7, 'CHINESE/FOOD/tao/Peking Roasted Duck.jpg'),
(85, ' Scrambled Eggs with', 600, 2, 7, 'CHINESE/FOOD/tao/Scrambled Eggs with Tomatoes.jpg'),
(86, 'Shrimp with Vermicel', 650, 2, 7, 'CHINESE/FOOD/tao/Shrimp with Vermicelli and Garlic.jpg'),
(87, 'SPRING ROLL (12 pcs)', 300, 2, 7, 'CHINESE/FOOD/tao/SPRING ROLL.jpg'),
(88, 'Wontons (12 pcs)', 600, 2, 7, 'CHINESE/FOOD/tao/Wontons.jpg'),
(89, 'Yangzhou Fried Rice', 850, 2, 7, 'CHINESE/FOOD/tao/Yangzhou Fried Rice.jpeg'),
(90, 'BEEF CHOWMEIN', 650, 2, 8, 'CHINESE/FOOD/bam bou/beef chowmein.jpg'),
(91, 'CHICKEN CHOWMEIN', 450, 2, 8, 'CHINESE/FOOD/bam bou/chicken chowmein.jpg'),
(92, 'CHICKEN FRIED RICE', 850, 2, 8, 'CHINESE/FOOD/bam bou/CHICKEN FRIED RICE.jpg'),
(93, 'CHICKEN SHASHLIK WIT', 800, 2, 8, 'CHINESE/FOOD/bam bou/CHICKEN SHASHLIK WITH RICE.jpg'),
(94, ' Dumplings (12 pcs)', 500, 2, 8, 'CHINESE/FOOD/bam bou/Dumplings.jpg'),
(95, 'Hot Pot', 600, 2, 8, 'CHINESE/FOOD/bam bou/Hot Pot.jpg'),
(96, 'Kung Pao Chicken', 850, 2, 8, 'CHINESE/FOOD/bam bou/Kung Pao Chicken.jpg'),
(97, 'MANCHURIAN', 800, 2, 8, 'CHINESE/FOOD/bam bou/MANCHURIAN.jpg'),
(98, 'Peking Roasted Duck', 1000, 2, 8, 'CHINESE/FOOD/bam bou/Peking Roasted Duck.jpg'),
(99, ' Scrambled Eggs with', 600, 2, 8, 'CHINESE/FOOD/bam bou/Scrambled Eggs with Tomatoes.jpg'),
(100, 'Shrimp with Vermicel', 650, 2, 8, 'CHINESE/FOOD/bam bou/Shrimp with Vermicelli and Garlic.jpg'),
(101, 'SPRING ROLL (12 pcs)', 300, 2, 8, 'CHINESE/FOOD/bam bou/SPRING ROLL.jpg'),
(102, 'Wontons (12 pcs)', 600, 2, 8, 'CHINESE/FOOD/bam bou/Wontons.jpg'),
(103, 'Yangzhou Fried Rice', 850, 2, 8, 'CHINESE/FOOD/bam bou/Yangzhou Fried Rice.jpg'),
(104, 'CHICKEN CHOWMEIN', 450, 2, 7, 'CHINESE/FOOD/tao/chicken chowmein.jpg'),
(105, 'BEEF BURGER', 300, 3, 9, 'Fast Food/food/Hardee\'s/BEEF BURGER.jpg'),
(106, 'CHICKEN BROAST', 350, 3, 9, 'Fast Food/food/Hardee\'s/CHICKEN BROAST.jpg'),
(107, 'CHICKEN BURGER', 250, 3, 9, 'Fast Food/food/Hardee\'s/CHICKEN BURGER.jpg'),
(108, 'CHICKEN NUGGETS (12 ', 600, 3, 9, 'Fast Food/food/Hardee\'s/CHICKEN NUGGETS.jpg'),
(109, 'CHICKEN WINGS (12 PC', 870, 3, 9, 'Fast Food/food/Hardee\'s/CHICKEN WINGS.jpg'),
(110, 'CHICKEN WRAP', 500, 3, 9, 'Fast Food/food/Hardee\'s/CHICKEN WRAP.jpg'),
(111, 'CHICKEN ZINGER BURGE', 450, 3, 9, 'Fast Food/food/Hardee\'s/CHICKEN ZINGER BURGER.jpg'),
(112, 'CLUB SANDWICH', 450, 3, 9, 'Fast Food/food/Hardee\'s/CLUB SANDWICH.jpg'),
(113, 'DACO TACO', 400, 3, 9, 'Fast Food/food/Hardee\'s/DACO TACO.jpeg'),
(114, 'FRENCH FRIES', 150, 3, 9, 'Fast Food/food/Hardee\'s/FRENCH FRIES.jpg'),
(115, 'HOT DOG', 400, 3, 9, 'Fast Food/food/Hardee\'s/HOT DOG.jpg'),
(116, 'CHICKEN BROAST', 350, 3, 10, 'Fast Food/food/KFC/CHICKEN BROAST.jpg'),
(117, 'CHICKEN BURGER', 250, 3, 10, 'Fast Food/food/KFC/CHICKEN BURGER.jpg'),
(118, 'CHICKEN NUGGETS (12 ', 600, 3, 10, 'Fast Food/food/KFC/CHICKEN NUGGETS.jpg'),
(119, 'CHICKEN WINGS (12 PC', 870, 3, 10, 'Fast Food/food/KFC/CHICKEN WINGS.jpg'),
(120, 'CHICKEN WRAP', 500, 3, 10, 'Fast Food/food/KFC/CHICKEN WRAP.jpg'),
(121, 'CHICKEN ZINGER BURGE', 450, 3, 10, 'Fast Food/food/KFC/CHICKEN ZINGER BURGER.jpg'),
(122, 'CLUB SANDWICH', 450, 3, 10, 'Fast Food/food/KFC/CLUB SANDWICH.jpg'),
(123, 'DACO TACO', 400, 3, 10, 'Fast Food/food/KFC/DACO TACO.jpeg'),
(124, 'FRENCH FRIES', 150, 3, 10, 'Fast Food/food/KFC/FRENCH FRIES.jpg'),
(125, 'HOT DOG', 400, 3, 10, 'Fast Food/food/KFC/HOT DOG.jpg'),
(126, 'BEEF BURGER', 300, 3, 10, 'Fast Food/food/KFC/BEEF BURGER.jpg'),
(127, 'BEEF BURGER', 300, 3, 11, 'Fast Food/food/boviChic/BEEF BURGER.jpg'),
(128, 'CHICKEN BROAST', 350, 3, 11, 'Fast Food/food/boviChic/CHICKEN BROAST.jpg'),
(129, 'CHICKEN BURGER', 250, 3, 11, 'Fast Food/food/boviChic/CHICKEN BURGER.jpg'),
(130, 'CHICKEN NUGGETS (12 ', 600, 3, 11, 'Fast Food/food/boviChic/CHICKEN NUGGETS.jpg'),
(131, 'CHICKEN WINGS (12 PC', 870, 3, 11, 'Fast Food/food/boviChic/CHICKEN WINGS.jpg'),
(132, 'CHICKEN WRAP', 500, 3, 11, 'Fast Food/food/boviChic/CHICKEN WRAP.jpg'),
(133, 'CHICKEN ZINGER BURGE', 450, 3, 11, 'Fast Food/food/boviChic/CHICKEN ZINGER BURGER.jpg'),
(134, 'CLUB SANDWICH', 450, 3, 11, 'Fast Food/food/boviChic/CLUB SANDWICH.jpg'),
(135, 'DACO TACO', 400, 3, 11, 'Fast Food/food/boviChic/DACO TACO.jpeg'),
(136, 'FRENCH FRIES', 150, 3, 11, 'Fast Food/food/boviChic/FRENCH FRIES.jpg'),
(137, 'HOT DOG', 400, 3, 11, 'Fast Food/food/boviChic/HOT DOG.jpg'),
(138, 'BEEF BURGER', 300, 3, 12, 'Fast Food/food/Howdy/BEEF BURGER.jpg'),
(139, 'CHICKEN BROAST', 350, 3, 12, 'Fast Food/food/Howdy/CHICKEN BROAST.jpg'),
(140, 'CHICKEN BURGER', 250, 3, 12, 'Fast Food/food/Howdy/CHICKEN BURGER.jpg'),
(141, 'CHICKEN NUGGETS (12 ', 600, 3, 12, 'Fast Food/food/Howdy/CHICKEN NUGGETS.jpg'),
(142, 'CHICKEN WINGS (12 PC', 870, 3, 12, 'Fast Food/food/Howdy/CHICKEN WINGS.jpg'),
(143, 'CHICKEN WRAP', 500, 3, 12, 'Fast Food/food/Howdy/CHICKEN WRAP.jpg'),
(144, 'CHICKEN ZINGER BURGE', 450, 3, 12, 'Fast Food/food/Howdy/CHICKEN ZINGER BURGER.jpg'),
(145, 'CLUB SANDWICH', 450, 3, 12, 'Fast Food/food/Howdy/CLUB SANDWICH.jpg'),
(146, 'DACO TACO', 400, 3, 12, 'Fast Food/food/Howdy/DACO TACO.jpeg'),
(147, 'FRENCH FRIES', 150, 3, 12, 'Fast Food/food/Howdy/FRENCH FRIES.jpg'),
(148, 'HOT DOG', 400, 3, 12, 'Fast Food/food/Howdy/HOT DOG.jpg'),
(149, 'AFGHANI BEEF BOTI (6', 250, 4, 13, 'bbq/food/MONAL/AFGHANI BEEF BOTI.jpg'),
(150, 'BEEF BOTI PLATE', 400, 4, 13, 'bbq/food/MONAL/BEEF BOTI PLATE.jpg'),
(151, 'CHICKEN BOTI PLATE', 300, 4, 13, 'bbq/food/MONAL/CHICKEN BOTI PLATE.jpg'),
(152, 'CHICKEN TIKKA (LEG)', 250, 4, 13, 'bbq/food/MONAL/CHICKEN TIKKA (LEG).jpg'),
(153, 'CHICKEN TIKKA (CHEST', 300, 4, 13, 'bbq/food/MONAL/CHICKEN TIKKA.jpg'),
(154, 'GOLA KABAB', 400, 4, 13, 'bbq/food/MONAL/GOLA KABAB.jpg'),
(155, 'MALAI BOTI', 300, 4, 13, 'bbq/food/MONAL/MALAI BOTI.jpg'),
(156, 'MUTTON RIBS', 1050, 4, 13, 'bbq/food/MONAL/MUTTON CHOMPS.jpg'),
(157, 'MUTTON CHOMPS (6 pcs', 880, 4, 13, 'bbq/food/MONAL/MUTTON RIBS.jpg'),
(158, 'RESHMI KABAB', 350, 4, 13, 'bbq/food/MONAL/RESHMI KABAB.jpg'),
(159, 'AFGHANI BEEF BOTI (6', 250, 4, 14, 'bbq/food/HAVELI/AFGHANI BEEF BOTI.jpg'),
(160, 'BEEF BOTI PLATE', 400, 4, 14, 'bbq/food/HAVELI/BEEF BOTI PLATE.jpg'),
(161, 'CHICKEN BOTI PLATE', 300, 4, 14, 'bbq/food/HAVELI/CHICKEN BOTI PLATE.jpg'),
(162, 'CHICKEN TIKKA (LEG)', 250, 4, 14, 'bbq/food/HAVELI/CHICKEN TIKKA (LEG).jpg'),
(163, 'CHICKEN TIKKA (CHEST', 300, 4, 14, 'bbq/food/HAVELI/CHICKEN TIKKA.jpg'),
(164, 'GOLA KABAB', 400, 4, 14, 'bbq/food/HAVELI/GOLA KABAB.jpg'),
(165, 'MALAI BOTI', 300, 4, 14, 'bbq/food/HAVELI/MALAI BOTI.jpg'),
(166, 'MUTTON RIBS', 1050, 4, 14, 'bbq/food/HAVELI/MUTTON CHOMPS.jpg'),
(167, 'MUTTON CHOMPS (6 pcs', 880, 4, 14, 'bbq/food/HAVELI/MUTTON RIBS.jpg'),
(168, 'RESHMI KABAB', 350, 4, 14, 'bbq/food/HAVELI/RESHMI KABAB.jpeg'),
(169, 'AFGHANI BEEF BOTI (6', 250, 4, 15, 'bbq/food/BBQ TONIGHT/AFGHANI BEEF BOTI.jpg'),
(170, 'BEEF BOTI PLATE', 400, 4, 15, 'bbq/food/BBQ TONIGHT/BEEF BOTI PLATE.jpg'),
(171, 'CHICKEN BOTI PLATE', 300, 4, 15, 'bbq/food/BBQ TONIGHT/CHICKEN BOTI PLATE.jpg'),
(172, 'CHICKEN TIKKA (LEG)', 250, 4, 15, 'bbq/food/BBQ TONIGHT/CHICKEN TIKKA (LEG).jpg'),
(173, 'CHICKEN TIKKA (CHEST', 300, 4, 15, 'bbq/food/BBQ TONIGHT/CHICKEN TIKKA.jpg'),
(174, 'GOLA KABAB', 400, 4, 15, 'bbq/food/BBQ TONIGHT/GOLA KABAB.jpg'),
(175, 'MALAI BOTI', 300, 4, 15, 'bbq/food/BBQ TONIGHT/MALAI BOTI.jpg'),
(176, 'MUTTON RIBS', 1050, 4, 15, 'bbq/food/BBQ TONIGHT/MUTTON CHOMPS.jpg'),
(177, 'MUTTON CHOMPS (6 pcs', 880, 4, 15, 'bbq/food/BBQ TONIGHT/MUTTON RIBS.jpg'),
(178, 'RESHMI KABAB', 350, 4, 15, 'bbq/food/BBQ TONIGHT/RESHMI KABAB.jpeg'),
(179, 'AFGHANI BEEF BOTI (6', 250, 4, 16, 'bbq/food/NANDO\'S/AFGHANI BEEF BOTI.jpg'),
(180, 'BEEF BOTI PLATE', 400, 4, 16, 'bbq/food/NANDO\'S/BEEF BOTI PLATE.jpg'),
(181, 'CHICKEN BOTI PLATE', 300, 4, 16, 'bbq/food/NANDO\'S/CHICKEN BOTI PLATE.jpg'),
(182, 'CHICKEN TIKKA (LEG)', 250, 4, 16, 'bbq/food/NANDO\'S/CHICKEN TIKKA (LEG).jpg'),
(183, 'CHICKEN TIKKA (CHEST', 300, 4, 16, 'bbq/food/NANDO\'S/CHICKEN TIKKA.jpg'),
(184, 'GOLA KABAB', 400, 4, 16, 'bbq/food/NANDO\'S/GOLA KABAB.jpg'),
(185, 'MALAI BOTI', 300, 4, 16, 'bbq/food/NANDO\'S/MALAI BOTI.jpg'),
(186, 'MUTTON RIBS', 1050, 4, 16, 'bbq/food/NANDO\'S/MUTTON CHOMPS.jpg'),
(187, 'MUTTON CHOMPS (6 pcs', 880, 4, 16, 'bbq/food/NANDO\'S/MUTTON RIBS.jpg'),
(188, 'RESHMI KABAB', 350, 4, 16, 'bbq/food/NANDO\'S/RESHMI KABAB.jpg'),
(189, 'CAKE SLICE', 450, 6, 17, 'Desserts/Food/DELIZIA/CAKE SLICE.webp'),
(190, 'CHOCOLATE BROWNIES (', 220, 6, 17, 'Desserts/Food/DELIZIA/CHOCOLATE BROWNIES.webp'),
(191, 'CHOCOLATE COOKIES (6', 1200, 6, 17, 'Desserts/Food/DELIZIA/CHOCOLATE COOKIES.webp'),
(192, 'CHOCOLATE LAVA CAKE', 1200, 6, 17, 'Desserts/Food/DELIZIA/CHOCOLATE LAVA CAKE.jpg'),
(193, 'CHURROS (6PCS)', 450, 6, 17, 'Desserts/Food/DELIZIA/CHURROS.jpg'),
(194, 'Crepe', 1450, 6, 17, 'Desserts/Food/DELIZIA/Crepe.webp'),
(195, 'DONUTS (6 PCS)', 250, 6, 17, 'Desserts/Food/DELIZIA/DONUTS.webp'),
(196, 'ICE CREAM PACK (1 LT', 660, 6, 17, 'Desserts/Food/DELIZIA/ICE CREAM PACK.jpg'),
(197, 'MINI PANCAKES (12 PC', 890, 6, 17, 'Desserts/Food/DELIZIA/MINI PANCAKES.jpg'),
(198, 'SPECIAL KULFI (PACK ', 880, 6, 17, 'Desserts/Food/DELIZIA/SPECIAL KULFI.webp'),
(199, 'SUNDAE (ANY FLAVOR)', 480, 6, 17, 'Desserts/Food/DELIZIA/SUNDAE.webp'),
(200, 'WAFFLE SANDWICH', 350, 6, 17, 'Desserts/Food/DELIZIA/WAFFLE SANDWICH.jpg'),
(201, 'CAKE SLICE', 450, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/CAKE SLICE.jpg'),
(202, 'CHOCOLATE BROWNIES (', 220, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/CHOCOLATE BROWNIES.webp'),
(203, 'CHOCOLATE COOKIES (6', 1200, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/CHOCOLATE COOKIES.webp'),
(204, 'CHOCOLATE LAVA CAKE', 1200, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/CHOCOLATE LAVA CAKE.jpg'),
(205, 'CHURROS (6PCS)', 450, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/CHURROS.jpg'),
(206, 'Crepe', 1450, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/Crepe.webp'),
(207, 'DONUTS (6 PCS)', 250, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/DONUTS.jpg'),
(208, 'ICE CREAM PACK (1 LT', 660, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/ICE CREAM PACK.jpg'),
(209, 'MINI PANCAKES (12 PC', 890, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/MINI PANCAKES.jpg'),
(210, 'SPECIAL KULFI (PACK ', 880, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/SPECIAL KULFI.jpg'),
(211, 'SUNDAE (ANY FLAVOR)', 480, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/SUNDAE.webp'),
(212, 'WAFFLE SANDWICH', 350, 6, 18, 'Desserts/Food/WAFFLES AND BEYOND/WAFFLE SANDWICH.jpg'),
(213, 'CAKE SLICE', 450, 6, 19, 'Desserts/Food/DUNKIN DONUTS/CAKE SLICE.webp'),
(214, 'CHOCOLATE BROWNIES (', 220, 6, 19, 'Desserts/Food/DUNKIN DONUTS/CHOCOLATE BROWNIES.webp'),
(215, 'CHOCOLATE COOKIES (6', 1200, 6, 19, 'Desserts/Food/DUNKIN DONUTS/CHOCOLATE COOKIES.webp'),
(216, 'CHOCOLATE LAVA CAKE', 1200, 6, 19, 'Desserts/Food/DUNKIN DONUTS/CHOCOLATE LAVA CAKE.jpg'),
(217, 'CHURROS (6PCS)', 450, 6, 19, 'Desserts/Food/DUNKIN DONUTS/CHURROS.webp'),
(218, 'Crepe', 1450, 6, 19, 'Desserts/Food/DUNKIN DONUTS/Crepe.webp'),
(219, 'DONUTS (6 PCS)', 250, 6, 19, 'Desserts/Food/DUNKIN DONUTS/DONUTS.webp'),
(220, 'ICE CREAM PACK (1 LT', 660, 6, 19, 'Desserts/Food/DUNKIN DONUTS/ICE CREAM PACK.jpg'),
(221, 'MINI PANCAKES (12 PC', 890, 6, 19, 'Desserts/Food/DUNKIN DONUTS/MINI PANCAKES.jpg'),
(222, 'SPECIAL KULFI (PACK ', 880, 6, 19, 'Desserts/Food/DUNKIN DONUTS/SPECIAL KULFI.jpg'),
(223, 'SUNDAE (ANY FLAVOR)', 480, 6, 19, 'Desserts/Food/DUNKIN DONUTS/SUNDAE.jpg'),
(224, 'WAFFLE SANDWICH', 350, 6, 19, 'Desserts/Food/DUNKIN DONUTS/WAFFLE SANDWICH.jpg'),
(225, 'CAKE SLICE', 450, 6, 20, 'Desserts/Food/KABABJEES BAKERS/CAKE SLICE.webp'),
(226, 'CHOCOLATE BROWNIES (', 220, 6, 20, 'Desserts/Food/KABABJEES BAKERS/CHOCOLATE BROWNIES.webp'),
(227, 'CHOCOLATE COOKIES (6', 1200, 6, 20, 'Desserts/Food/KABABJEES BAKERS/CHOCOLATE COOKIES.webp'),
(228, 'CHOCOLATE LAVA CAKE', 1200, 6, 20, 'Desserts/Food/KABABJEES BAKERS/CHOCOLATE LAVA CAKE.jpg'),
(229, 'CHURROS (6PCS)', 450, 6, 20, 'Desserts/Food/KABABJEES BAKERS/CHURROS.jpg'),
(230, 'Crepe', 1450, 6, 20, 'Desserts/Food/KABABJEES BAKERS/Crepe.webp'),
(231, 'DONUTS (6 PCS)', 250, 6, 20, 'Desserts/Food/KABABJEES BAKERS/DONUTS.jpg'),
(232, 'ICE CREAM PACK (1 LT', 660, 6, 20, 'Desserts/Food/KABABJEES BAKERS/ICE CREAM PACK.jpg'),
(233, 'MINI PANCAKES (12 PC', 890, 6, 20, 'Desserts/Food/KABABJEES BAKERS/MINI PANCAKES.jpg'),
(234, 'SPECIAL KULFI (PACK ', 880, 6, 20, 'Desserts/Food/KABABJEES BAKERS/SPECIAL KULFI.jpg'),
(235, 'SUNDAE (ANY FLAVOR)', 480, 6, 20, 'Desserts/Food/KABABJEES BAKERS/SUNDAE.jpg'),
(236, 'WAFFLE SANDWICH', 350, 6, 20, 'Desserts/Food/KABABJEES BAKERS/WAFFLE SANDWICH.jpg'),
(237, 'COCKTAIL', 350, 5, 21, 'Beverages/Food/STUDIO 7 TEAS/COCKTAIL.webp'),
(238, 'FALOODA', 350, 5, 21, 'Beverages/Food/STUDIO 7 TEAS/FALOODA.jpg'),
(239, 'FRESH FRUIT JUICE (A', 300, 5, 21, 'Beverages/Food/STUDIO 7 TEAS/FRESH FRUIT JUICE.webp'),
(240, 'MARGARITA', 350, 5, 21, 'Beverages/Food/STUDIO 7 TEAS/MARGARITA.jpg'),
(241, 'MILK SHAKE (ANY FLAV', 450, 5, 21, 'Beverages/Food/STUDIO 7 TEAS/MILK SHAKE.jpg'),
(242, 'SOFT DRINK 1.5LTR', 120, 5, 21, 'Beverages/Food/STUDIO 7 TEAS/SOFT DRINK 1.5LTR.jpg'),
(243, 'SOFT DRINK 500ML', 70, 5, 21, 'Beverages/Food/STUDIO 7 TEAS/SOFT DRINK.webp'),
(244, 'TEA', 60, 5, 21, 'Beverages/Food/STUDIO 7 TEAS/TEA.jpg'),
(245, 'COCKTAIL', 350, 5, 22, 'Beverages/Food/HAPPY ICE CREAM/COCKTAIL.webp'),
(246, 'FALOODA', 350, 5, 22, 'Beverages/Food/HAPPY ICE CREAM/FALOODA.jpg'),
(247, 'FRESH FRUIT JUICE (A', 300, 5, 22, 'Beverages/Food/HAPPY ICE CREAM/FRESH FRUIT JUICE.webp'),
(248, 'MARGARITA', 350, 5, 22, 'Beverages/Food/HAPPY ICE CREAM/MARGARITA.jpg'),
(249, 'MILK SHAKE (ANY FLAV', 450, 5, 22, 'Beverages/Food/HAPPY ICE CREAM/MILK SHAKE.jpg'),
(250, 'SOFT DRINK 1.5LTR', 120, 5, 22, 'Beverages/Food/HAPPY ICE CREAM/SOFT DRINK 1.5LTR.jpg'),
(251, 'SOFT DRINK 500ML', 70, 5, 22, 'Beverages/Food/HAPPY ICE CREAM/SOFT DRINK.webp'),
(252, 'TEA', 60, 5, 22, 'Beverages/Food/HAPPY ICE CREAM/TEA.jpg'),
(253, 'COCKTAIL', 350, 5, 23, 'Beverages/Food/AGHA JUICE/COCKTAIL.webp'),
(254, 'FALOODA', 350, 5, 23, 'Beverages/Food/AGHA JUICE/FALOODA.jpg'),
(255, 'FRESH FRUIT JUICE (A', 300, 5, 23, 'Beverages/Food/AGHA JUICE/FRESH FRUIT JUICE.webp'),
(256, 'MARGARITA', 350, 5, 23, 'Beverages/Food/AGHA JUICE/MARGARITA.jpg'),
(257, 'MILK SHAKE (ANY FLAV', 450, 5, 23, 'Beverages/Food/AGHA JUICE/MILK SHAKE.jpg'),
(258, 'SOFT DRINK 1.5LTR', 120, 5, 23, 'Beverages/Food/AGHA JUICE/SOFT DRINK 1.5LTR.jpg'),
(259, 'SOFT DRINK 500ML', 70, 5, 23, 'Beverages/Food/AGHA JUICE/SOFT DRINK.webp'),
(260, 'TEA', 60, 5, 23, 'Beverages/Food/AGHA JUICE/TEA.jpg'),
(261, 'COCKTAIL', 350, 5, 24, 'Beverages/Food/MEHRAN ICE CREAM/COCKTAIL.webp'),
(262, 'FALOODA', 350, 5, 24, 'Beverages/Food/MEHRAN ICE CREAM/FALOODA.jpg'),
(263, 'FRESH FRUIT JUICE (A', 300, 5, 24, 'Beverages/Food/MEHRAN ICE CREAM/FRESH FRUIT JUICE.webp'),
(264, 'MARGARITA', 350, 5, 24, 'Beverages/Food/MEHRAN ICE CREAM/MARGARITA.jpg'),
(265, 'MILK SHAKE (ANY FLAV', 450, 5, 24, 'Beverages/Food/MEHRAN ICE CREAM/MILK SHAKE.jpg'),
(266, 'SOFT DRINK 1.5LTR', 120, 5, 24, 'Beverages/Food/MEHRAN ICE CREAM/SOFT DRINK 1.5LTR.jpg'),
(267, 'SOFT DRINK 500ML', 70, 5, 24, 'Beverages/Food/MEHRAN ICE CREAM/SOFT DRINK.webp'),
(268, 'TEA', 60, 5, 24, 'Beverages/Food/MEHRAN ICE CREAM/TEA.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `orderr`
--

CREATE TABLE `orderr` (
  `order_id` int(11) NOT NULL,
  `cus_id` int(11) DEFAULT NULL,
  `rider_id` int(11) DEFAULT NULL,
  `order_date` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `discount` float DEFAULT 0,
  `total_price` float DEFAULT NULL,
  `discounted_price` float DEFAULT NULL,
  `checkout` varchar(20) DEFAULT '0',
  `future` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `orderr`
--

INSERT INTO `orderr` (`order_id`, `cus_id`, `rider_id`, `order_date`, `discount`, `total_price`, `discounted_price`, `checkout`, `future`) VALUES
(2, 3, NULL, '2021-12-20 19:51:26', 0, NULL, NULL, '0', 0),
(3, 1, NULL, '2021-12-20 19:51:26', 0, NULL, NULL, '0', 0),
(12, 5, NULL, '2021-12-20 19:51:26', 0, 3100, NULL, '0', 0),
(15, 2, 6, '2021-12-20 19:51:26', 0, 1400, NULL, '1', 0),
(16, 2, 3, '2021-12-20 19:51:26', 0, 1100, NULL, '1', 0),
(19, 6, 2, '2021-12-20 19:51:26', 20, 3450, 2760, '1', 0),
(24, 2, 3, '2021-12-20 19:51:26', 10, 520, 468, '1', 0),
(25, 2, 6, '2021-12-20 19:51:26', 10, 2370, 2133, '1', 0),
(26, 2, 6, '2021-12-20 19:51:26', 10, 1650, 1485, '1', 0),
(27, 2, 5, '2021-12-20 20:25:34', 20, 650, 520, '1', 1),
(29, 2, 4, '2021-12-21 01:06:51', 20, 1290, 1032, '1', 1),
(30, 2, 1, '2021-12-21 01:39:45', 20, 1010, 808, '1', 1),
(31, 2, 4, '2021-12-21 01:55:09', 20, 1620, 1296, '1', 1);

-- --------------------------------------------------------

--
-- Table structure for table `restaurant`
--

CREATE TABLE `restaurant` (
  `res_id` int(11) NOT NULL,
  `res_name` varchar(20) NOT NULL,
  `category_id` int(11) DEFAULT NULL,
  `url_image` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `restaurant`
--

INSERT INTO `restaurant` (`res_id`, `res_name`, `category_id`, `url_image`) VALUES
(1, 'BELLA VITA', 1, 'ITALIAN/RESTAURANTS/BELLA_VITA.jpg'),
(2, 'DELFRIO', 1, 'ITALIAN/RESTAURANTS/DELFRIO.jpg'),
(3, 'THE HOT SPOT', 1, 'ITALIAN/RESTAURANTS/HOTSPOT.jpg'),
(4, 'PIZZA HUT', 1, 'ITALIAN/RESTAURANTS/PIZZAHUT.jpg'),
(5, 'GINSOY', 2, 'CHINESE/RESTAURANTS/Ginsoy.jpg'),
(6, 'XIAN', 2, 'CHINESE/RESTAURANTS/xian.jpg'),
(7, 'TAO', 2, 'CHINESE/RESTAURANTS/tao.png'),
(8, 'BAM BOU', 2, 'CHINESE/RESTAURANTS/bam-bou.png'),
(9, 'HARDEE\'S', 3, 'Fast Food/restaurants/hardee\'s.jpg'),
(10, 'KFC', 3, 'Fast Food/restaurants/kfc.png'),
(11, 'BOVICHIC', 3, 'Fast Food/restaurants/boviChic.png'),
(12, 'HOWDY', 3, 'Fast Food/restaurants/howdy.jpg'),
(13, 'MONAL', 4, 'bbq/restaurants/monal.jpg'),
(14, 'HAVELI KEBAB AND GRI', 4, 'bbq/restaurants/haveli.jpg'),
(15, 'BBQ TONIGHT', 4, 'bbq/restaurants/bbq tonight.jpg'),
(16, 'NANDO\'S ', 4, 'bbq/restaurants/nando\'s.png'),
(17, 'DELIZIA', 6, 'Desserts/Restaurant/delizia.jpg'),
(18, 'WAFFLES AND BEYOND', 6, 'Desserts/Restaurant/WAFFLES AND BEYOD.jpg'),
(19, 'DUNKIN DONUTS', 6, 'Desserts/Restaurant/DUNKIN DONUTS.jpg'),
(20, 'KABABJEES BAKERS', 6, 'Desserts/Restaurant/kababjees bakers.jpg'),
(21, 'STUDIO 7 TEAS', 5, 'Beverages/Restaurant/studio 7 teas.png'),
(22, 'HAPPY ICE CREAM', 5, 'Beverages/Restaurant/happy ice cream.jpg'),
(23, 'AGHA JUICE', 5, 'Beverages/Restaurant/agha juice.jpg'),
(24, 'MEHRAN ICE CREAM', 5, 'Beverages/Restaurant/mehran ice cream.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `reviews`
--

CREATE TABLE `reviews` (
  `rev_id` int(11) NOT NULL,
  `cus_id` int(11) DEFAULT NULL,
  `order_id` int(11) DEFAULT NULL,
  `review` varchar(200) DEFAULT NULL,
  `review_date` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `reviews`
--

INSERT INTO `reviews` (`rev_id`, `cus_id`, `order_id`, `review`, `review_date`) VALUES
(1, 2, 29, 'The service was excellent.', '2021-12-20 19:00:00'),
(3, 1, 2, 'Service was excellent.', '2021-12-20 19:00:00');

-- --------------------------------------------------------

--
-- Table structure for table `rider`
--

CREATE TABLE `rider` (
  `rider_id` int(11) NOT NULL,
  `rider_name` varchar(20) DEFAULT NULL,
  `rider_phone` varchar(20) DEFAULT NULL,
  `vehicle_num_plate` varchar(20) DEFAULT NULL,
  `rider_cnic` varchar(20) DEFAULT NULL,
  `driving_license` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `rider`
--

INSERT INTO `rider` (`rider_id`, `rider_name`, `rider_phone`, `vehicle_num_plate`, `rider_cnic`, `driving_license`) VALUES
(1, 'Ali Rehman', '03130298109', 'KAQ-8091', '42101-7256742-9', 123456),
(2, 'Qazi Nauman', '03130298109', 'KAQ-8092', '42101-7256742-9', 123456),
(3, 'Muhammad Ahmed', '03130298109', 'KAQ-8093', '42101-7256742-9', 123456),
(4, 'Zohaib Yousuf', '03130298109', 'BIZZ-6969', '42101-7256742-9', 123456),
(5, 'Adnan Qazi', '03130298109', 'AGENT-109', '42101-7256742-9', 123456),
(6, 'Kamran', '03040880308', '42101-7255653-3', 'KAQ-5049', 123567),
(7, 'Kamran', '03040880308', '42101-7255653-3', 'KAQ-5049', 123567);

-- --------------------------------------------------------

--
-- Table structure for table `suborder`
--

CREATE TABLE `suborder` (
  `sub_order_id` int(11) NOT NULL,
  `res_id` int(11) DEFAULT NULL,
  `order_id` int(11) DEFAULT NULL,
  `category_id` int(11) DEFAULT NULL,
  `food_id` int(11) DEFAULT NULL,
  `food_price` int(11) DEFAULT NULL,
  `topping_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `suborder`
--

INSERT INTO `suborder` (`sub_order_id`, `res_id`, `order_id`, `category_id`, `food_id`, `food_price`, `topping_id`) VALUES
(29, 6, 2, 2, 64, 650, NULL),
(30, 6, 2, 2, 65, 450, NULL),
(31, 9, 3, 3, 105, 300, NULL),
(32, 9, 3, 3, 107, 250, NULL),
(33, 10, 3, 3, 116, 350, NULL),
(46, 1, 12, 1, 1, 950, NULL),
(47, 6, 12, 2, 64, 650, NULL),
(48, 16, 12, 4, 181, 300, NULL),
(49, 20, 12, 6, 228, 1200, NULL),
(52, 6, 15, 2, 64, 650, NULL),
(53, 15, 15, 4, 171, 300, NULL),
(54, 23, 15, 5, 257, 450, NULL),
(55, 12, 16, 3, 140, 250, NULL),
(56, 8, 16, 2, 92, 850, NULL),
(60, 4, 19, 1, 38, 1400, NULL),
(61, 10, 19, 3, 120, 500, NULL),
(62, 15, 19, 4, 172, 250, NULL),
(63, 20, 19, 6, 229, 450, NULL),
(64, 6, 19, 2, 66, 850, NULL),
(69, 9, 24, 3, 105, 300, NULL),
(70, 18, 24, 6, 202, 220, NULL),
(71, 15, 25, 4, 171, 300, NULL),
(72, 10, 25, 3, 119, 870, NULL),
(73, 19, 25, 6, 215, 1200, NULL),
(74, 5, 26, 2, 49, 650, NULL),
(75, 1, 26, 1, 3, 1000, NULL),
(76, 6, 27, 2, 64, 650, NULL),
(78, 5, 29, 2, 49, 650, 16),
(79, 10, 29, 3, 116, 350, NULL),
(80, 1, 30, 1, 5, 800, 4),
(81, 8, 31, 2, 92, 850, NULL),
(82, 20, 31, 6, 229, 450, NULL),
(83, 15, 31, 4, 169, 250, 8);

-- --------------------------------------------------------

--
-- Table structure for table `toppings`
--

CREATE TABLE `toppings` (
  `topping_id` int(11) NOT NULL,
  `topping_name` varchar(20) DEFAULT NULL,
  `topping_price` int(11) DEFAULT NULL,
  `category_id` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `toppings`
--

INSERT INTO `toppings` (`topping_id`, `topping_name`, `topping_price`, `category_id`) VALUES
(2, 'Extra Sauce', 50, 1),
(3, 'Extra Mustard', 120, 1),
(4, 'Extra Chicken', 210, 1),
(5, 'Extra Ketchup', 50, 3),
(6, 'Extra Mayonnaise', 40, 3),
(7, 'Extra Bacon', 30, 3),
(8, 'Barbecue Sauce', 70, 4),
(9, 'Hot Sauce', 50, 4),
(10, 'Ranch Dressing', 90, 4),
(11, 'Classic Butterscotch', 170, 6),
(12, 'Strawberry Sauce', 150, 6),
(13, 'Hot Fudge Sauce', 190, 6),
(14, 'Cole Slaw', 50, 2),
(15, 'Chicken Salad', 250, 2),
(16, 'Chinese Salad', 290, 2),
(17, 'Honey', 30, 5),
(18, 'Chocolate Syrup', 100, 5),
(19, 'Garnishes', 130, 5);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `address`
--
ALTER TABLE `address`
  ADD PRIMARY KEY (`address_id`),
  ADD KEY `cus_id` (`cus_id`);

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`admin_id`),
  ADD KEY `rider_id` (`rider_id`),
  ADD KEY `res_id` (`res_id`),
  ADD KEY `order_id` (`order_id`),
  ADD KEY `bill_id` (`bill_id`);

--
-- Indexes for table `billing`
--
ALTER TABLE `billing`
  ADD PRIMARY KEY (`bill_id`),
  ADD KEY `cus_id` (`cus_id`),
  ADD KEY `order_id` (`order_id`),
  ADD KEY `rider_id` (`rider_id`);

--
-- Indexes for table `category`
--
ALTER TABLE `category`
  ADD PRIMARY KEY (`category_id`);

--
-- Indexes for table `creditcardinfo`
--
ALTER TABLE `creditcardinfo`
  ADD PRIMARY KEY (`s_no`),
  ADD KEY `cus_id` (`cus_id`);

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`cus_id`),
  ADD UNIQUE KEY `cus_email` (`cus_email`);

--
-- Indexes for table `food`
--
ALTER TABLE `food`
  ADD PRIMARY KEY (`food_id`),
  ADD KEY `category_id` (`category_id`),
  ADD KEY `res_id` (`res_id`);

--
-- Indexes for table `orderr`
--
ALTER TABLE `orderr`
  ADD PRIMARY KEY (`order_id`),
  ADD KEY `cus_id` (`cus_id`),
  ADD KEY `rider_id` (`rider_id`);

--
-- Indexes for table `restaurant`
--
ALTER TABLE `restaurant`
  ADD PRIMARY KEY (`res_id`),
  ADD KEY `category_id` (`category_id`);

--
-- Indexes for table `reviews`
--
ALTER TABLE `reviews`
  ADD PRIMARY KEY (`rev_id`),
  ADD KEY `cus_id` (`cus_id`),
  ADD KEY `order_id` (`order_id`);

--
-- Indexes for table `rider`
--
ALTER TABLE `rider`
  ADD PRIMARY KEY (`rider_id`);

--
-- Indexes for table `suborder`
--
ALTER TABLE `suborder`
  ADD PRIMARY KEY (`sub_order_id`),
  ADD KEY `res_id` (`res_id`),
  ADD KEY `order_id` (`order_id`),
  ADD KEY `category_id` (`category_id`),
  ADD KEY `food_id` (`food_id`);

--
-- Indexes for table `toppings`
--
ALTER TABLE `toppings`
  ADD PRIMARY KEY (`topping_id`),
  ADD KEY `category_id` (`category_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `address`
--
ALTER TABLE `address`
  MODIFY `address_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=36;

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `admin_id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `billing`
--
ALTER TABLE `billing`
  MODIFY `bill_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=55;

--
-- AUTO_INCREMENT for table `category`
--
ALTER TABLE `category`
  MODIFY `category_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `creditcardinfo`
--
ALTER TABLE `creditcardinfo`
  MODIFY `s_no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `customer`
--
ALTER TABLE `customer`
  MODIFY `cus_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `food`
--
ALTER TABLE `food`
  MODIFY `food_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=542;

--
-- AUTO_INCREMENT for table `orderr`
--
ALTER TABLE `orderr`
  MODIFY `order_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;

--
-- AUTO_INCREMENT for table `restaurant`
--
ALTER TABLE `restaurant`
  MODIFY `res_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=330;

--
-- AUTO_INCREMENT for table `reviews`
--
ALTER TABLE `reviews`
  MODIFY `rev_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `rider`
--
ALTER TABLE `rider`
  MODIFY `rider_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `suborder`
--
ALTER TABLE `suborder`
  MODIFY `sub_order_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=84;

--
-- AUTO_INCREMENT for table `toppings`
--
ALTER TABLE `toppings`
  MODIFY `topping_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `address`
--
ALTER TABLE `address`
  ADD CONSTRAINT `address_ibfk_1` FOREIGN KEY (`cus_id`) REFERENCES `customer` (`cus_id`);

--
-- Constraints for table `admin`
--
ALTER TABLE `admin`
  ADD CONSTRAINT `admin_ibfk_1` FOREIGN KEY (`rider_id`) REFERENCES `rider` (`rider_id`),
  ADD CONSTRAINT `admin_ibfk_2` FOREIGN KEY (`res_id`) REFERENCES `restaurant` (`res_id`),
  ADD CONSTRAINT `admin_ibfk_3` FOREIGN KEY (`order_id`) REFERENCES `orderr` (`order_id`),
  ADD CONSTRAINT `admin_ibfk_4` FOREIGN KEY (`bill_id`) REFERENCES `billing` (`bill_id`);

--
-- Constraints for table `billing`
--
ALTER TABLE `billing`
  ADD CONSTRAINT `billing_ibfk_1` FOREIGN KEY (`cus_id`) REFERENCES `customer` (`cus_id`),
  ADD CONSTRAINT `billing_ibfk_2` FOREIGN KEY (`order_id`) REFERENCES `orderr` (`order_id`),
  ADD CONSTRAINT `billing_ibfk_3` FOREIGN KEY (`rider_id`) REFERENCES `rider` (`rider_id`);

--
-- Constraints for table `creditcardinfo`
--
ALTER TABLE `creditcardinfo`
  ADD CONSTRAINT `creditcardinfo_ibfk_1` FOREIGN KEY (`cus_id`) REFERENCES `customer` (`cus_id`);

--
-- Constraints for table `food`
--
ALTER TABLE `food`
  ADD CONSTRAINT `food_ibfk_1` FOREIGN KEY (`category_id`) REFERENCES `category` (`category_id`),
  ADD CONSTRAINT `food_ibfk_2` FOREIGN KEY (`res_id`) REFERENCES `restaurant` (`res_id`);

--
-- Constraints for table `orderr`
--
ALTER TABLE `orderr`
  ADD CONSTRAINT `orderr_ibfk_1` FOREIGN KEY (`cus_id`) REFERENCES `customer` (`cus_id`),
  ADD CONSTRAINT `orderr_ibfk_2` FOREIGN KEY (`rider_id`) REFERENCES `rider` (`rider_id`);

--
-- Constraints for table `restaurant`
--
ALTER TABLE `restaurant`
  ADD CONSTRAINT `restaurant_ibfk_1` FOREIGN KEY (`category_id`) REFERENCES `category` (`category_id`);

--
-- Constraints for table `reviews`
--
ALTER TABLE `reviews`
  ADD CONSTRAINT `reviews_ibfk_1` FOREIGN KEY (`cus_id`) REFERENCES `customer` (`cus_id`),
  ADD CONSTRAINT `reviews_ibfk_2` FOREIGN KEY (`order_id`) REFERENCES `orderr` (`order_id`);

--
-- Constraints for table `suborder`
--
ALTER TABLE `suborder`
  ADD CONSTRAINT `suborder_ibfk_1` FOREIGN KEY (`res_id`) REFERENCES `restaurant` (`res_id`),
  ADD CONSTRAINT `suborder_ibfk_2` FOREIGN KEY (`order_id`) REFERENCES `orderr` (`order_id`),
  ADD CONSTRAINT `suborder_ibfk_3` FOREIGN KEY (`category_id`) REFERENCES `category` (`category_id`),
  ADD CONSTRAINT `suborder_ibfk_4` FOREIGN KEY (`food_id`) REFERENCES `food` (`food_id`);

--
-- Constraints for table `toppings`
--
ALTER TABLE `toppings`
  ADD CONSTRAINT `toppings_ibfk_1` FOREIGN KEY (`category_id`) REFERENCES `category` (`category_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
