var = (1..5).to_a.shuffle.join(' ')
system("./push_swap " + var + " >.moves")
system("cat .moves | wc -l | tr -d ' ' | tr '\n' ' '")
print "  Checker: "
system("cat .moves | ./checker_Mac " + var)
system("rm -f .moves")
