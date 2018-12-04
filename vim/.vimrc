call plug#begin('~/.vim/plugged')

Plug 'neomake/neomake'
Plug 'tmhedberg/SimpylFold'
"Plug 'google/yapf'
Plug 'mindriot101/vim-yapf'
Plug 'Valloric/YouCompleteMe'
Plug 'SirVer/ultisnips'
Plug 'rdnetto/YCM-Generator', { 'branch': 'stable'}
Plug 'honza/vim-snippets'
Plug 'ervandew/supertab'
Plug 'vim-syntastic/syntastic'
Plug 'nathanaelkane/vim-indent-guides'
Plug 'majutsushi/tagbar'
Plug 'davidhalter/jedi'
Plug 'neovim/python-client'
Plug 'zchee/deoplete-jedi'
Plug 'maralla/completor.vim' "autocomple for vim language
"dark terminal
Plug 'Shougo/deol.nvim'

if has('nvim')
  Plug 'Shougo/deoplete.nvim', { 'do': ':UpdateRemotePlugins' }
else
  Plug 'Shougo/deoplete.nvim'
  Plug 'roxma/nvim-yarp'
  Plug 'roxma/vim-hug-neovim-rpc'
endif

Plug 'scrooloose/nerdtree'
Plug 'francoiscabrol/ranger.vim'
Plug 'rbgrouleff/bclose.vim'
Plug 'tpope/vim-fugitive'


"to check
Plug 'scrooloose/nerdcommenter'
Plug 'tikhomirov/vim-glsl'
Plug 'ap/vim-buftabline'
Plug 'gikmx/ctrlp-obsession'
Plug 'tpope/vim-obsession'

"automatic closing of quotes, parenthesis, brackets, etc.
Plug 'Raimondi/delimitMate'

"switching between companion files (e.g. ".h" and ".cpp" files)
Plug 'derekwyatt/vim-fswitch'

"statusline
Plug 'powerline/powerline'

"search
Plug 'mileszs/ack.vim'
Plug 'rking/ag.vim'
Plug 'Chun-Yang/vim-action-ag'
Plug 'kien/ctrlp.vim'
Plug 'shougo/neomru.vim'
Plug 'Shougo/unite.vim' "todo lern
Plug 'Shougo/unite-session'
Plug 'Shougo/vimproc.vim', {'do' : 'make'} "unite require this plug"

"colors
"Plug 'jeaye/color_coded'
"Plug 'kien/rainbow_parentheses.vim'
"Plug 'luochen1990/rainbow'
Plug 'dracula/vim'
Plug 'morhetz/gruvbox'

" Entertainment
Plug 'dansomething/vim-hackernews'

call plug#end()

"deoplete
let g:deoplete#enable_at_startup = 1

set nowrap " zawijanie linii wylaczone
syntax enable " Włącza magię. Włączając w to przeglądarkę plików i kolorowanie składni
set showmode  " Pokazuje kiedy jesteś w trybie wprowadzania/nadpisywania
set showcmd   " Kiedy komenda się wykonuje, pokazuj ją w pasku stanu
set autoindent  " Dodawaj wcięcia inteligentnie, zamiast cały czas powracać do samego początku wiersza
set autoread " auto reload file

set wildmenu "pokazuje wszystkie komendy
set wildmode=list:longest
set wildignore='.svn,*.o,*.d,*.a,*.dll,*.pyc,*.bak,*.exe,*.jpg,*.jpeg,*.png,*.gif'

set history=5000

set hlsearch  "Podświetlaj wszystkie wyniki wyszukiwania
set showmatch "Podświetlaj odpowiadające nawiasy, klamry itd.
set ignorecase "Ignoruj wielkość znaków przy wyszukiwaniu
set smartcase "Jeżeli wyszukiwana fraza zawiera wielkie litery, przestań ignorować wielkość znaków
set incsearch


set noswapfile  " swap file off
set nobackup
set nowritebackup
set relativenumber

set shiftwidth=4 "ustawienie wciecia na 4 spacje
set fileformat=unix
set tabstop=4
set softtabstop=4
set expandtab

" Python shiftwidth, tabstop, softtabstop
autocmd FileType python set sw=4
autocmd FileType python set ts=4
autocmd FileType python set sts=4

"au BufNewFile,BufRead *.py
"    \ set tabstop=4
"    \ set softtabstop=4
"    \ set shiftwidth=4
"    \ set textwidth=79
"    \ set expandtab
"    \ set autoindent
"   \ set fileformat=unix

set encoding=utf-8

"show file name
autocmd BufReadPost,FileReadPost,BufNewFile * call system("tmux rename-window " . expand("%"))

"filetype plugin on

set modifiable

if has('unnamedplus')
  set clipboard=unnamed,unnamedplus
endif


let mapleader = ","
let mapleader2 = " "
"let maplocalleader = "\\"

match Ignore /\r$/

" Syntax coloring lines that are too long just slows down the world
set synmaxcol=2048

"backspace
set laststatus=2

"set statusline+=%F "show full path name

" Show linenumbers
set number

"replace veriable name
" For local replace
nnoremap gr gd[{V%::s/<C-R>///gc<left><left><left>

" For global replace
nnoremap gR gD:%s/<C-R>///gc<left><left><left>

"c++,c programming
":set tags+=tags;

autocmd BufWritePre * %s/\s\+$//e       "remove trailing spaces


"SimpylFold
let g:SimpylFold_docstring_preview = 1
nnoremap <space> za

"python
let python_highlight_all = 1
" Override go-to.definition key shortcut to Ctrl-]
"let g:pymode_rope_goto_definition_bind = "<C-]>

" Override run current python file key shortcut to Ctrl-Shift-e
"let g:pymode_run_bind = "<C-S-e>"

" Override view python doc key shortcut to Ctrl-Shift-d
"let g:pymode_doc_bind = "<C-S-d>"

"jedi
"let g:jedi#completions_enabled = 0

"yapf
map <C-Y> :call Yapf()<cr>
imap <C-Y> <c-o>:call Yapf()<cr>
"let g:yapf_style = "google"
let g:yapf_style = "pep8"

"enable mouse
set mouse=a
set bs=2 "make backspace behave like normal again

"RainbowParentheses
"let g:rainbow_active = 1
"let g:rainbow_conf = {
"    \'guifgs': ['royalblue3', 'darkorange3', 'seagreen3', 'firebrick'],
"	\'ctermfgs': ['lightblue', 'lightyellow', 'lightcyan', 'lightmagenta'],
"	\'operators': '_,_',
"	\'parentheses': ['start=/(/ end=/)/ fold', 'start=/\[/ end=/\]/ fold', 'start=/{/ end=/}/ fold'],
"    \ 'separately': {
"    \   'cpp': {
"    \     'parentheses': [
"    \       'start=/(/ end=/)/ fold',
"    \       'start=/\[/ end=/\]/ fold',
"    \       'start=/{/ end=/}/ fold',
"    \       'start=/\(\(\<operator\>\)\@<!<\)\&[a-zA-Z0-9_]\@<=<\ze[^<]/ end=/>/'] } } }

syntax on
filetype plugin indent on


"colorscheme molokai
"set guifont=Monospace\ 9

set t_Co=256
syntax on
"set background=light
"colorscheme mayansmoke
"colorscheme pyte
"colorscheme zenburn
color dracula

"set background=dark
"colorscheme gruvbox

"rainbow
""todo au FileType c,cpp,objc,objcpp call rainbow#load()
"let g:rainbow_active = 1
"https://github.com/oblitum/rainbow

"These commands open folds
"set foldopen=block,insert,jump,mark,percent,quickfix,search,tag,undo

"Allow cursor to go to "invalid" places
"set virtualedit=block

"set gdefault

"set cursorline

"set nolazyredraw
"set pastetoggle=<F2>

"set list
"set listchars=tab:>.,trail:.,extends:#,nbsp:.

"auto completion options
"et completeopt=menu,menuone,longest
"#let g:SuperTabDefaultCompletionType = 'context'
autocmd FileType *
      \if &omnifunc != '' |
      \call SuperTabChain(&omnifunc, "<c-p>") |
      \call SuperTabSetDefaultCompletionType("<c-x><c-u>") |
      \endif


"size of popup menu
"set pumheight=15

"ignore whitespaces in diff
"set diffopt+=iwhite



"set encoding=utf-8
"set scrolloff=10
"set autoindent
"set cindent
"set showmode
"set showcmd
"set hidden
"set wildmode=list:longest
"set wildignore='.svn,*.o,*.d,*.a'
"set visualbell
"set ttyfast
set ruler                            "show line and column number"
set backspace=indent,eol,start
"set formatoptions=qrn1
"set textwidth=120
"set title
"set shellslash
"set cpoptions=ces$

"set autoread
"set nobackup
"set nowb


"vim-cpp-enhanced-highlight
"let g:cpp_class_scope_highlight = 1
"let g:cpp_member_variable_highlight = 1
"let g:cpp_class_decl_highlight = 1
"let g:cpp_experimental_simple_template_highlight = 1
"let g:cpp_experimental_template_highlight = 1
"let g:cpp_concepts_highlight = 1

"color_coded
let g:color_coded_enabled = 1
"let g:color_coded_filetypes = ['c', 'cpp', 'objc']


"CtrlP
set runtimepath^=~/.vim/plugin/ctrlp.vim
let g:ctrlp_cmd = 'CtrlP .'
set wildignore +=*.txt,*.dia,*.xls,*.cmake,*.dll,*.manifest,*.bat,*.o,*.d
set wildignore +=*/bin/*
"set wildignore +=*/3rdParty/*,*/AcceptanceTests/*,*/Docs/*,*/TauTester/*,*/output/*,*/Projects/*,*/CP_GRM/*,*/CP_SDL/*

""YouCompleteMe
"let g:ycm_global_ycm_extra_conf = './.ycm_extra_conf.py'
" These are the tweaks I apply to YCM's config, you don't need them but they
" might help.

" YCM gives you popups and splits by default that some people might not
" like, so these should tidy it up a bit for you.

"my config:
"let g:ycm_add_preview_to_completeopt=0
"let g:ycm_confirm_extra_conf=0
"set completeopt-=preview
" let g:ycm_always_populate_location_list = 1 ":lopen and :lclose

" syntastic
" This does what it says on the tin. It will check your file on open too, not just on save.
" You might not want this, so just leave it out if you don't.
"let g:syntastic_check_on_open=1
"
" ------------------------------------------------------------------------------
" UltiSnips stuff
let g:UltiSnipsExpandTrigger = "<nop>"
inoremap <expr> <CR> pumvisible() ? "<C-R>=UltiSnips#ExpandSnippetOrJump()<CR>" : "\<CR>"
"let g:UltiSnipsSnippetDirectories = ['/$HOME/.config/nvim/UltiSnips', 'UltiSnips']
" -------------------------------------------------------------------------------

"remkalath config
" autocomplete
"let g:ycm_global_ycm_extra_conf = '$HOME/config_files/nvim/.ycm_extra_conf.py'
let g:ycm_auto_trigger = 1
let g:ycm_min_num_of_chars_for_completion = 1
let g:ycm_confirm_extra_conf = 0
let g:ycm_autoclose_preview_window_after_insertion = 1
set backspace=indent,eol,start

" ---------------------------------- "
" Configure YouCompleteMe python
" ---------------------------------- "

""let g:ycm_collect_identifiers_from_tags_files = 1 " Let YCM read tags from Ctags file
"let g:ycm_use_ultisnips_completer = 1 " Default 1, just ensure
"let g:ycm_seed_identifiers_with_syntax = 1 " Completion for programming language's keyword
"let g:ycm_complete_in_comments = 1 " Completion in comments
"let g:ycm_complete_in_strings = 1 " Completion in string
"
"let g:ycm_filepath_completion_use_working_dir = 1
"let g:ycm_collect_identifiers_from_tags_files = 1
"
"let g:ycm_key_list_select_completion = ['<C-j>', '<Down>']
"let g:ycm_key_list_previous_completion = ['<C-k>', '<Up>']
""let g:ycm_cxx_default_flags = ['-Wall', '-Wconversion', '-std=c++14']

"" Goto definition with F3
"let g:ycm_autoclose_preview_window_after_completion=1
map <leader>g  :YcmCompleter GoToDefinitionElseDeclaration<CR>
"nnoremap <Leader>g :YcmCompleter GoTo<CR>
nnoremap <Leader>r :YcmCompleter GoToReferences<CR>
nnoremap <Leader>d :YcmCompleter GoToDeclaration<CR>
nnoremap <Leader>c :YcmCompleter GoToDefinition<CR>

" ---------------------------------- "
" Common
" ---------------------------------- "

"run node on actual js file
"nnoremap <leader>r :!echo "==================\n\n" & node %:p<CR>
"nnoremap <silent>r :!echo "==================\n\n" & python %:p
"nnoremap <silent>r :!clear && python %:p<CR>

"jshint
"let jshint2_read = 1
"let jshint2_save = 1
"let jshint2_close = 0
"let jshint2_confirm = 0
"let jshint2_color = 0
"let jshint2_error = 0
"let jshint2_min_height = 3
"let jshint2_max_height = 12

" jshint validation
"nnoremap <silent><F1> :JSHint<CR>
"inoremap <silent><F1> <C-O>:JSHint<CR>
"vnoremap <silent><F1> :JSHint<CR>
"
"" " show next jshint error
"nnoremap <silent><F2> :lnext<CR>
"inoremap <silent><F2> <C-O>:lnext<CR>
"vnoremap <silent><F2> :lnext<CR>
"
"" " show previous jshint error
"nnoremap <silent><F3> :lprevious<CR>
"inoremap <silent><F3> <C-O>:lprevious<CR>
"vnoremap <silent><F3> :lprevious<CR>


"tern
"let g:tern_map_keys = 1
"let g:tern_show_argument_hints = 'on_hold'
"let g:tern_show_signature_in_pum = 1
"
"nnoremap  <leader>td :TernDoc<CR>
"nnoremap  <leader>tb :TernDocBrowse<CR>
"nnoremap  <leader>tt :TernType<CR>
"nnoremap  <leader>td :TernDef<CR>
"nnoremap  <leader>tpd :TernDefPreview<CR>
"nnoremap  <leader>tsd :TernDefSplit<CR>
"nnoremap  <leader>ttd :TernDefTab<CR>
"nnoremap  <leader>tr :TernRefs<CR>
"nnoremap  <leader>tR :TernRename<CR>


"Ranger:
"
let g:NERDTreeHijackNetrw = 0  " add this line if you use NERDTree
let g:ranger_replace_netrw = 1  " open ranger when vim open a directory
let g:ranger_map_keys = 0
map <leader>f :Ranger<CR>

function! Easymotion()

"Easymotion
" Gif config
    map  / <Plug>(easymotion-sn)
    omap / <Plug>(easymotion-tn)

" These `n` & `N` mappings are options. You do not have to map `n` & `N` to
"EasyMotion.
" Without these mappings, `n` & `N` works fine. (These mappings just provide
" different highlight method and have some other features )
    map  n <Plug>(easymotion-next)
    map  N <Plug>(easymotion-prev)

endfunction

command! Easymotion call Easymotion()

"Easymotion
" Gif config
""ap  / <Plug>(easymotion-sn)
""map / <Plug>(easymotion-tn)

" These `n` & `N` mappings are options. You do not have to map `n` & `N` to
"EasyMotion.
" Without these mappings, `n` & `N` works fine. (These mappings just provide
" different highlight method and have some other features )
"map  n <Plug>(easymotion-next)
"map  N <Plug>(easymotion-prev)


silent! nmap <leader>nt :NERDTreeToggle<CR>
silent! map <leader>nf :NERDTreeFind<CR>


"nnoremap <silent>f :NERDTreeFind<CR>
"inoremap <silent>f :NERDTreeFind<CR>
"vnoremap <silent>f :NERDTreeFind<CR>

"let g:NERDTreeMapActivateNode="<F3>"
"let g:NERDTreeMapPreview="<F4>"

let NERDTreeIgnore=['.d$[[file]]', '.o$[[file]]', '.gcda$[[file]]', '.gcno$[[file]]']



"https://github.com/nathanaelkane/vim-indent-guides.git
let g:indent_guides_auto_colors = 0
autocmd VimEnter,Colorscheme * :hi IndentGuidesEven ctermbg=238
autocmd VimEnter,Colorscheme * :hi IndentGuidesOdd ctermbg=236

"delimitMate
imap <C-c> <CR><Esc>O



"BufNewFile - starting to edit a file that doesn't exist
"BufRead - starting to edit a new buffer, after reading the file
au BufNewFile,BufRead *.ttcn set filetype=ttcn
au BufNewFile,BufRead *.LOG set filetype=rlh
au BufNewFile,BufRead *.log set filetype=rlh





" Window movements; I do this often enough to warrant using up M-arrows on this"A
noremap <Up> <NOP>
noremap <Down> <NOP>
noremap <Left> <NOP>
noremap <Right> <NOP>
inoremap  <Up>     <NOP>
inoremap  <Down>   <NOP>
inoremap  <Left>   <NOP>
inoremap  <Right>  <NOP>

"better indentation
vnoremap < <gv
vnoremap > >gv

"Automatic reloading of .vimrc
autocmd! bufwritepost .vimrc source %


map <leader>cc :botright cope<cr>
map <leader>cq :cclose<cr>
map <leader>cn :cn<cr>
map <leader>cp :cp<cr>

"nnoremap <Space> i<Space><Esc>
"nnoremap <CR> _i<Enter><Esc>
nnoremap <Backspace> _i<Backspace><Esc>
"nnoremap <Tab> %
"vnoremap <Tab> %
"nnoremap <leader><space> :noh<cr>
"nnoremap <leader>c :CommandT
nnoremap <leader>a :Ack
nnoremap <leader>ac :Ack --type=cc --type=cpp

"vertical and horisontal split
nnoremap <leader>v <C-w>v<C-w>r
nnoremap <leader>h <C-w>s<C-w>r

"moving between open windows
nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>

nmap <S-Tab> :FSHere <cr>

"Quick quit command
noremap <leader>q :quit<CR> " Quit current window
noremap <leader>Q :qa!<CR>  " Quit all windows

map <leader>n <esc>:tabprevious<CR>
map <leader>m <esc>:tabnext<CR>

" map sort function to a key
vnoremap <leader>s :sort<CR>



"syntastic
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 0 "if 0 error list is close open :lopen
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0

let g:syntastic_perl_checkers = ['perl']
let g:syntastic_enable_perl_checker = 1
let g:syntastic_enable_sh_checker = 1



" syntastic validation
nnoremap <silent><F1> :lopen<CR>
inoremap <silent><F1> <C-O>:lopen<CR>
vnoremap <silent><F1> :lopen<CR>

" " show next error
nnoremap <silent><F2> :lnext<CR>
inoremap <silent><F2> <C-O>:lnext<CR>
vnoremap <silent><F2> :lnext<CR>

" " show previous error
nnoremap <silent><F3> :lprevious<CR>
inoremap <silent><F3> <C-O>:lprevious<CR>
vnoremap <silent><F3> :lprevious<CR>


"jedi
let g:jedi#completions_enabled = 0
let g:jedi#goto_command = "<leader>jg"
"let g:jedi#goto_assignments_command = "<leader>a"
"let g:jedi#goto_definitions_command = ""
"let g:jedi#documentation_command = "K"
"let g:jedi#usages_command = "<leader>jr"
"let g:jedi#completions_command = "<C-Space>"
let g:jedi#rename_command = "<leader>jr"


let g:agprg="<custom-ag-path-goes-here> --column"

"Unite config
""Unite
call unite#filters#matcher_default#use(['matcher_fuzzy'])
call unite#filters#sorter_default#use(['sorter_rank'])
"call unite#custom#source('file_rec/async','sorters','sorter_rank', )
""replacing unite with ctrl-p
let g:unite_data_directory='~/.vim/.cache/unite'
let g:unite_enable_start_insert=1
let g:unite_source_history_yank_enable=1
let g:unite_prompt='» '
let g:unite_split_rule = 'botright'
"use ag instead of grep
if executable('ag')
    let g:unite_source_grep_command='ag'
    let g:unite_source_grep_default_opts='--nocolor --nogroup -S -C0  --ignore "bin*" --ignore "build*" --ignore "tags"'
    let g:unite_source_grep_recursive_opt=''
endif
nnoremap <leader>up :Unite -auto-resize file file_mru file_rec/async<cr>
let g:unite_source_history_yank_enable = 1
nnoremap <leader>b :Unite buffer<cr>
nnoremap <leader>uy :Unite history/yank<cr>

" Press <leader>ll to re-open last Unite buffer
nnoremap <silent><leader>ll :<C-u>UniteResume<CR>

nnoremap <leader>ug :Unite grep:.<cr>
nnoremap <silent><leader>s :<C-u>Unite -no-quit -keep-focus grep:.:-G\ '[ch]pp' <CR>
nnoremap <silent><leader>lg :<C-u>Unite -no-quit -keep-focus grep<CR>
nnoremap <silent><leader>k :<C-u>UniteWithCursorWord -no-quit -keep-focus grep:.:-G\ 'py' <CR>
nnoremap <silent><leader>c :<C-u>UniteWithCursorWord -no-quit -keep-focus grep:.:-G\ '\.\(c\|cpp\|h\)' <CR>
"nnoremap <leader>lj :Unite -start-insert -no-quit -keep-focus grep:.:-G\ 'py'<C-R><C-w><CR>

"===============================================================================
" Normal Mode Ctrl Key Mappins
"===============================================================================


" Ctrl-s: not warking

" Ctrl-g: find references
nnoremap <C-G> :UniteWithCursorWord grep:. <CR>
vnoremap <C-G> <C-C>:UniteWithCursorWord grep:. <CR>
inoremap <C-G> <C-O>:UniteWithCursorWord grep:. <CR>

"nnoremap <silent><Leader>A :UniteWithCursorWord -silent -auto-preview
""            \ -winheight=40 -no-quit grep<CR>

"nnoremap <c-g> :Unite grep:. <cr>

" Ctrl-q: Visual block mode

" Ctrl-w: Window management

" Ctrl-e: Find (e)verything

" Ctrl-r: Command history using Unite, this matches my muscle memory in zsh

" Ctrl-t: TODO

" Ctrl-t*: Tab operations (When was the last time I used tabs?)
" nnoremap <c-t><c-n> :tabnew<cr>
" nnoremap <c-t><c-w> :tabclose<cr>
" nnoremap <c-t><c-j> :tabprev<cr>
" nnoremap <c-t><c-h> :tabprev<cr>
" nnoremap <c-t><c-k> :tabnext<cr>
" nnoremap <c-t><c-l> :tabnext<cr>
" let g:lasttab = 1
" nnoremap <c-t><c-t> :exe "tabn ".g:lasttab<cr>
" autocmd MyAutoCmd TabLeave * let g:lasttab = tabpagenr()

" Ctrl-y: Yanks

" Ctrl-u: Scroll half a screen up smoothly

" Ctrl-i: Go forward in the jumplist, also realigns screen. See mapping for
" <M-s>

" Ctrl-o: Go back in the jumplist, also realign the screen
" nnoremap <c-o> <c-o>zzzv

" Ctrl-p: Find MRU and buffers

" Ctrl-[: Esc

" Ctrl-]: Go forward in tag stack

" Ctrl-\: Quick outline

" Ctrl-a*: Dispatch related

" Ctrl-z: save
noremap <C-Z> :update<CR>
vnoremap <C-Z> <C-C>:update<CR>
inoremap <C-Z> <C-O>:update<CR>


" Removes the ^M character from the end of every line
function! RemoveM()
    :%s/^M$//g
endfunction

" Replaces the ^M character with a carraige return native to the system
function! ReplaceM()
    :%s/^M/\r/g
endfunction

" Removes superfluous white space from the end of a line
function! RemoveWhiteSpace()
    :%s/\s*$//g
    :'^
    "`.
endfunction


" start the terminal in the given path by typing :t on the minibuffer
:ab _terminal_ :!urxvt -bg black --geometry 85x47+683+0&\|<CR>
:ab fpath :echo expand('%:p')



" Command Reference
" ------------------------------------------------------------

" *                     - searches for word under cursor
" gd                    - finds definition of variable/function under cursor
" ga                    - prints the ascii value of character under cursor
" gf                    - opens file under the cursor (in split view)
" gi                    - goes to insert mode in the same spot as you last inserted
" ~                     - changes case of character
" :r !<cmd>             - reads the output of the shell <cmd> into the file
" :% s/hello/A/gc       - typical search and replace command

" :% !tidy              - runs the code through the 'tidy' program

" :runtime! syntax/2html.vim
" :10,40TOhtml

" command reference ->  " za : fold toggle  toggles between a fold being opened and closed (zA does it recursively)
"                       " zc : fold close   close 1 fold under the cursor (zC does it recursively)
                        " zo : fold open    open 1 fold under the cursor (zO does it recursively)
                        " zm : fold more    increases foldlevel by 1 (zM opens all folds)
                        " zr : fold reduce  decreses foldlevel by 1 (zR closes all folds)

 " :retab                - when expandtab is set, replace all tabs in the file with the # of spaces defined in 'shiftwidth'
 " :retab!               - when expandtab is not set, replace the number of spaces in 'shiftwidth' with a tab
 if has("cscope")
     set csprg=/usr/bin/cscope
     set csto=0
     set cst
     set nocsverb
     " add any database in current directory
     if filereadable("cscope.out")
         cs add cscope.out
     " else add database pointed to by environment
     elseif $CSCOPE_DB != ""
         cs add $CSCOPE_DB
     endif
     set csverb

     "   's'   symbol: find all references to the token under cursor
     "   'g'   global: find global definition(s) of the token under cursor
     "   'c'   calls:  find all calls to the function name under cursor
     "   't'   text:   find all instances of the text under cursor
     "   'e'   egrep:  egrep search for the word under cursor
     "   'f'   file:   open the filename under cursor
     "   'i'   includes: find files that include the filename under cursor
     "   'd'   called: find functions that function under cursor calls
     nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>
     nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>
     nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>
     nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>
     nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>
     nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
     nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
     nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>
 endif


vmap Q gq
nmap Q gqap

"tagbar short
nmap <leader>T :TagbarOpenAutoClose<cr>


"tagbar
nmap <F8> :TagbarToggle<CR>

function! Preserve(command)
    "Preparation: save last search and cursor position.
    let _s = @/
    let l = line(".")
    let c = col(".")
    "Do the business
    execute a:command

    "Clean up: restore previous search history and cursor position
    let @/ = _s
    call cursor(l, c)
endfunction

"Clean trailing whitespaces
nmap _$ :call Preserve("%s/\\s\\+$//e")<CR>

function! ToggleMinimap()

    if exists ("s:isMini") && s:isMini == 0
        let s:isMini = 1
    else
        let s:isMini = 0
    end

    if (s:isMini == 0)

        "save current visible lines
        let s:firstLine = line("w0")
        let s:lastLine  = line("w$")

        "don't change window size
        let c = &columns * 20
        let l = &lines * 20
        "exe "set columns=" . c
        "exe "set lines=" . l

        "make font small
        set guifont=Monospace:h2

        exe 'normal zR'

        "highlight lines which were visible
        let s:lines = ""
        for i in range(s:firstLine, s:lastLine)
            let s:lines = s:lines . "\\%" . i . "l"
            if i < s:lastLine
                let s:lines = s:lines . "\\|"
            endif
        endfor

        hi Visible guifg=black guibg=lightblue
        exec 'match Visible /' . s:lines . '/'
        set nocursorline
        nmap <s-j> 10j
        nmap <s-k> 10k

    else

        set guifont=DejaVu\ Sans\ Mono:h10
        hi clear Visible
        set cursorline
        nunmap <s-j>
        nunmap <s-k>

    endif

endfunction

command! ToggleMinimap call ToggleMinimap()

function! CloseHiddenBuffers()
" figure out which buffers are visible in any tab
  let visible = {}
  for t in range(1, tabpagenr('$'))
    for b in tabpagebuflist(t)
      let visible[b] = 1
    endfor
  endfor
" close any buffer that are loaded and not visible
  let l:tally = 0
  for b in range(1, bufnr('$'))
    if bufloaded(b) && !has_key(visible, b)
      let l:tally += 1
      exe 'bw ' . b
    endif
  endfor
  echon "Deleted " . l:tally . " buffers"
endfun

command! CloseHiddenBuffers call CloseHiddenBuffers()

"nmap <leader>m : ToggleMinimap<CR>
