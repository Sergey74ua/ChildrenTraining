#Вставка JOIN
SELECT `orders`.`order_number`, `people`.`name`, `shop`.`title` FROM `people`
	INNER JOIN `orders` ON `people`.`id` = `orders`.`person_id`
    INNER JOIN `shop` ON `shop`.`id` = `orders`.`shop_id`
ORDER BY `orders`.`order_number`;