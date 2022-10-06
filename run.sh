make stl
./ft_containers vector
./ft_containers stack
./ft_containers map

make fclean re
./ft_containers vector
./ft_containers stack
./ft_containers map

make fclean

if diff ftVectorOutput stdVectorOutput
then
    echo "[VECTOR]: ✅"
else
    echo "[VECTOR]: ❌"
fi

# STACK
if diff ftStackOutput stdStackOutput
then
    echo "[STACK]:  ✅"
else
    echo "[STACK]:  ❌"
fi

# MAP
if diff ftMapOutput stdMapOutput
then
    echo "[MAP]:    ✅"
else
    echo "[MAP]:    ❌"
fi