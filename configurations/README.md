## Configurations

When  setting up the configurations, do these in addition to putting the configuration files in the right place:

### `init.vim`

1. Install [vim-plug](https://github.com/junegunn/vim-plug)
    - For Neovim on Linux, you can run
    ```sh -c 'curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'```
2. Install plugins by running `:PlugInstall` twice in Neovim **after saving `init.vim` and restarting Neovim.
3. Install LSP servers. This can be done by running `:LspInstall`, which suggests servers based on the filetype of file currently being edited, or by running `:LspInstall [server name]` explicitly.
