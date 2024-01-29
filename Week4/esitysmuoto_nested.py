def nested(num):

    if num % 3 == 0:

        print ("Fizz")

    else:

        if num % 5 == 0:

            print ("Buzz")

        else:

            print (num)

import dis; dis.dis(nested) 