# Testing and Scripts

## Norminette

### No header warning

`norminette | grep -vE HEADER`

this will ignore the HEADER warning at this stage of development
the header eats away the history from vscode because of autosave
so its a good idea not to put the headers until we're readier to deliver


### Silent header and comment
`norminette | grep -vE "HEADER|COMM"`

complimentary in case you like to leave comments inside functions

## Running and Leak check

* `make parse` for testing &

* `make parsev` for valgrind, checks simple mem and file descriptor leaks

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