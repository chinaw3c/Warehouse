echo "你好,刘傲天主人!"
"按F6运行Python version::python3 
map <F6> :Autopep8<CR> :w<CR> :call RunPython()<CR>
function RunPython()
    let mp = &makeprg
    let ef = &errorformat
    let exeFile = expand("%:t")
    setlocal makeprg=python3\ -u
    set efm=%C\ %.%#,%A\ \ File\ \"%f\"\\,\ line\ %l%.%#,%Z%[%^\ ]%\\@=%m
    silent make %
    copen
    let &makeprg = mp
    let &errorformat = ef
endfunction

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'Valloric/YouCompleteMe'
Plugin 'VundleVim/Vundle.vim'
call vundle#end()

map <F5> :NERDTreeToggle<CR>
" YouCompleteMe配置
let g:ycm_global_ycm_extra_conf='~/.vim/bundle/YouCompleteMe/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
set pumheight=10
let g:ycm_autoclose_preview_window_after_completion=1
" 禁止缓存匹配项,每次都重新生成匹配项"
let g:ycm_cache_omnifunc=0
"字符串中也开启补全"
let g:ycm_complete_in_strings = 1
"离开插入模式后自动关闭预览窗口"
autocmd InsertLeave * if pumvisible() == 0|pclose|endif
"回车即选中当前项"
let g:ycm_semantic_triggers =  {
  \   'c' : ['->', '.','re![_a-zA-z0-9]'],
  \   'objc' : ['->', '.', 're!\[[_a-zA-Z]+\w*\s', 're!^\s*[^\W\d]\w*\s',
  \             're!\[.*\]\s'],
  \   'ocaml' : ['.', '#'],
  \   'cpp,objcpp' : ['->', '.', '::','re![_a-zA-Z0-9]'],
  \   'perl' : ['->'],
  \   'php' : ['->', '::'],
  \   'cs,java,javascript,typescript,d,python,perl6,scala,vb,elixir,go' : ['.'],
  \   'ruby' : ['.', '::'],
  \   'lua' : ['.', ':'],
  \   'erlang' : [':'],
  \ }



set runtimepath+=~/.vim_runtime

source ~/.vim_runtime/vimrcs/basic.vim
source ~/.vim_runtime/vimrcs/filetypes.vim
source ~/.vim_runtime/vimrcs/plugins_config.vim
source ~/.vim_runtime/vimrcs/extended.vim

try
source ~/.vim_runtime/my_configs.vim
catch
endtry
"新建.c,.h,.sh,.java文件，自动插入文件头 

autocmd BufNewFile *.cpp,*.[ch],*.sh,*.java exec ":call SetTitle()" 

""定义函数SetTitle，自动插入文件头 

func SetTitle() 

    "如果文件类型为.sh文件 

    if &filetype == 'sh' 

        call setline(1,"\#########################################################################") 

        call append(line("."), "\# File Name: ".expand("%")) 

        call append(line(".")+1, "\# Author: 刘傲天") 

        call append(line(".")+2, "\# mail: 1151172004@qq.com") 

        "原来的时间形式比较复杂，不喜欢，改变一下

        "call append(line(".")+3, "\# Created Time: ".strftime("%c")) 
        call append(line(".")+3, "\# Created Time: ".strftime("%Y-%m-%d",localtime()))

        call append(line(".")+4, "\#########################################################################") 

        call append(line(".")+5, "\#!/bin/bash") 

        call append(line(".")+6, "") 

    else 

        call setline(1, "/*************************************************************************") 

        call append(line("."), "    > File Name: ".expand("%")) 

        call append(line(".")+1, "    > Author: 刘傲天") 

        call append(line(".")+2, "    > Mail: 1151172004@qq.com ") 

        " 同样的 改变时间格式
        "call append(line(".")+3, "    > Created Time: ".strftime("%c")) 
        call append(line(".")+3, "    > Created Time: ".strftime("%Y-%m-%d",localtime()))

        call append(line(".")+4, " ************************************************************************/") 

        call append(line(".")+5, "")

    endif

    if &filetype == 'cpp'

        call append(line(".")+6, "#include<iostream>")
        call append(line(".")+7, " ")
        call append(line(".")+8, "using namespace std;")
        call append(line(".")+9, "")
        call append(line(".")+10, "int main(void)")
    call append(line(".")+11, "{")
    call append(line(".")+12, " ")
    call append(line(".")+13, "    return 0;")
    call append(line(".")+14, "}")

    endif

    if &filetype == 'c'

        call append(line(".")+6, "#include<stdio.h>")

        call append(line(".")+7, "")
        call append(line(".")+8, "int main(void)")
    call append(line(".")+9, "{")
    call append(line(".")+10, " ")
    call append(line(".")+11, "    return 0;")
    call append(line(".")+12, "}")

    endif

    "新建文件后，自动定位到文件末尾

    autocmd BufNewFile * normal G

endfunc 

" Suzzz：  模仿上面，新建python文件时，添加文件头

autocmd BufNewFile *py exec ":call SetPythonTitle()"

func SetPythonTitle()
    call setline(1,"#hello")
    call append( line(".")," " )
    call append(line(".")+1,"\# File Name: ".expand("%")) 
    call append(line(".")+2, "\# Author: 刘傲天") 
    call append(line(".")+3, "\# mail: 1151172004@qq.com") 
    call append(line(".")+4, "\# Created Time: ".strftime("%Y-%m-%d",localtime()))    
endfunc


