## Testing and Scripts

### Resources

* [Raycasting: Parmadi](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
* [Raycasting: Wheeler](https://timallanwheeler.com/blog/2023/04/01/wolfenstein-3d-raycasting-in-c/)
* [Raycsating: Lode](https://lodev.org/cgtutor/raycasting.html)
* [Trigonometry](https://www.askamathematician.com/2014/10/q-why-radians/)

### Silent header and comment

ignores header warning on norminette, it destroys autosave on vsc
```
norminette | grep -vE HEADER
norminette | grep -vE "HEADER|COMM"
```

### Running and Leak check

for quick execs and valgrind
```
make parse
make parsev
```

<!-- 

## Code block

```
int main(){}
```

## Authors

Name  
[@LinkTemplate](https://github.com)

## Version History

* See [commit change]() or See [release history]()

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details -->
