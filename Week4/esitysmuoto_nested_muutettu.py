def nested(num):

    if num % 5 == 0:

            print ("Buzz")

    else:

        if num % 3 == 0:

            print ("Fizz")
        
        else:

            print (num)

import dis; dis.dis(nested) 