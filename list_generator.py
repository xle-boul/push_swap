# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    list_generator.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 20:46:33 by xle-boul          #+#    #+#              #
#    Updated: 2022/06/01 10:49:32 by xle-boul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
import sys

arg = int(sys.argv[1])
list = [0] * 10000
for i in range (-4999, 5000):
	list[i] = i
rdm_list = random.sample(list, k = arg)

print(*rdm_list, sep = " ")
