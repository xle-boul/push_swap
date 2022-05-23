# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    list_generator.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 20:46:33 by xle-boul          #+#    #+#              #
#    Updated: 2022/05/23 11:46:28 by xle-boul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random

list = [0] * 10000
for i in range (0, 10000):
	list[i] = i
rdm_list = random.sample(list, k = 100)

print(*rdm_list, sep = " ")
