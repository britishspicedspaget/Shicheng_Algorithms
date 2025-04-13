call plug#begin('~/.vim/plugged')

" Plugin configurations
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'scrooloose/nerdtree'
Plug 'Xuyuanp/nerdtree-git-plugin'
Plug 'tiagofumo/vim-nerdtree-syntax-highlight'
Plug 'ryanoasis/vim-devicons'
Plug 'airblade/vim-gitgutter'
Plug 'ctrlpvim/ctrlp.vim'
Plug 'scrooloose/nerdcommenter'
Plug 'christoomey/vim-tmux-navigator'
Plug 'morhetz/gruvbox'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'HerringtonDarkholme/yats.vim'
Plug 'maxmellon/vim-jsx-pretty'
Plug 'projekt0n/github-nvim-theme'
Plug 'dense-analysis/ale'

call plug#end()

" Enable ALE
let g:ale_linters_explicit = 1
let g:ale_fix_on_save = 0
let g:ale_sign_error = 'E'
let g:ale_sign_warning = 'W'
let g:ale_virtualtext_cursor = 1  " Show error messages inline
let g:ale_virtualtext_prefix = '>> '

" Linter Configuration by Language
let g:ale_linters = {
\   'c': ['gcc', 'clang'],
\   'cpp': ['g++', 'clang++'],
\   'cs': ['omnisharp'],
\   'python': ['pylint'],
\   'html': ['tidy'],
\   'css': ['stylelint'],
\   'javascript': ['eslint'],
\   'java': ['javac']
\}

" Auto-fixers (optional for format and cleanup)
let g:ale_fixers = {}

" General Settings for ALE
let g:ale_completion_enabled = 1
let g:ale_lint_on_text_changed = 'always'
let g:ale_lint_on_insert_leave = 1
let g:ale_lint_on_save = 1
let g:ale_lint_on_enter = 1

" Display results in loclist and quickfix
let g:ale_open_list = 1
let g:ale_keep_list_window_open = 0


" Colorscheme setup
set bg=dark
colorscheme gruvbox

" Basic settings
set hlsearch
set backspace=indent,eol,start
set guifont=DejaVu\ Sans:s12
set mouse=a
set ignorecase
set belloff=all
set foldmethod=indent
set number
set smarttab
set cindent
set tabstop=4
set shiftwidth=4
set expandtab
set laststatus=2
set statusline+=%F
set signcolumn=yes
set hidden
set nobackup
set nowritebackup
set cmdheight=2
set updatetime=300
set shortmess+=c

" Key mappings
let mapleader = ","
nmap <leader>n :NERDTreeFocus<CR>
nmap <C-n> :NERDTreeToggle<CR>
vmap ++ <plug>NERDCommenterToggle
nmap ++ <plug>NERDCommenterToggle
nnoremap gb :ls<CR>:b<Space>
nnoremap ge yiw:%s/<C-r>0//g<Left><Left>
nnoremap = <C-w>>
noremap <Leader>y "+y
noremap <Leader>p "+p
vmap <Leader>y "+y
vmap <Leader>p "+p
nnoremap <leader>r @:
nnoremap - <C-w><
tnoremap <Esc> <C-\><C-n>
inoremap <C-BS> <C-w>

" Resize window bindings
nnoremap <Leader>w+ :vertical resize +5<CR>
nnoremap <Leader>w- :vertical resize -5<CR>
nnoremap <Leader>t :tabs<CR>

" Sync open file with NERDTree
function! IsNERDTreeOpen()        
  return exists("t:NERDTreeBufName") && (bufwinnr(t:NERDTreeBufName) != -1)
endfunction

function! SyncTree()
  if &modifiable && IsNERDTreeOpen() && strlen(expand('%')) > 0 && !&diff
    NERDTreeFind
    wincmd p
  endif
endfunction

autocmd BufRead * call SyncTree()

" Coc.nvim settings for multiple languages
let g:coc_global_extensions = [
  \ 'coc-snippets',
  \ 'coc-pairs',
  \ 'coc-tsserver',            
  \ 'coc-eslint',                          
  \ 'coc-json',                
  \ 'coc-html',            
  \ 'coc-clangd',              
  \ 'coc-csharp',            
  \ 'coc-java',                
  \ 'coc-pyright',            
  \ ]

" Language-specific settings
autocmd FileType c,cpp setlocal tabstop=4 shiftwidth=4 expandtab
autocmd FileType cs setlocal tabstop=4 shiftwidth=4 expandtab
autocmd FileType nasm setlocal tabstop=4 shiftwidth=4 expandtab
autocmd FileType html setlocal tabstop=2 shiftwidth=2 expandtab
autocmd FileType java setlocal tabstop=4 shiftwidth=4 expandtab
autocmd FileType python setlocal tabstop=4 shiftwidth=4 expandtab

" Enable auto-completion with <C-space>
inoremap <silent><expr> <c-space> coc#refresh()

" Show documentation on hover
nnoremap <silent> K :call <SID>show_documentation()<CR>
function! s:show_documentation()
  if (index(['vim','help'], &filetype) >= 0)
    execute 'h '.expand('<cword>')
  else
    call CocAction('doHover')
  endif
endfunction

" Use [g and ]g to navigate diagnostics
nmap <silent> [g <Plug>(coc-diagnostic-prev)
nmap <silent> ]g <Plug>(coc-diagnostic-next)

" Use K to show documentation
nnoremap <silent> K :call <SID>show_documentation()<CR>

" Mapping for code actions
nnoremap <F2> <Plug>(coc-rename)
xmap <leader>f <Plug>(coc-format-selected)
nmap <leader>f <Plug>(coc-format-selected)
nmap <leader>a <Plug>(coc-codeaction-selected)
nmap <leader>ac <Plug>(coc-codeaction)

" Use <C-d> for range selection
nmap <silent> <C-d> <Plug>(coc-range-select)
xmap <silent> <C-d> <Plug>(coc-range-select)

" Use `:Format` to format current buffer
command! -nargs=0 Format :call CocAction('format')

" Highlight symbol under cursor on CursorHold
autocmd CursorHold * silent call CocActionAsync('highlight')

" Autocmd for signature help
augroup mygroup
  autocmd!
  autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
  autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
augroup end

" Highlight currently open buffer in NERDTree
autocmd BufEnter * call SyncTree()

" Other useful mappings
noremap <silent> <expr> j (v:count == 0 ? 'gj' : 'j')
noremap <silent> <expr> k (v:count == 0 ? 'gk' : 'k')

" Prevent accidental deletion of text
nnoremap x "_x
nnoremap d "_d
nnoremap D "_D
vnoremap d "_d
nnoremap <leader>d ""d
nnoremap <leader>D ""D
vnoremap <leader>d ""d

" NERDTree mappings
let g:NERDTreeIgnore = ['^node_modules$']
let g:NERDTreeGitStatusWithFlags = 1

" Enable airline and theme settings
let g:airline_theme='gruvbox'
let g:airline_powerline_fonts = 1
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#formatter = 'default'

" Enable Prettier
command! -nargs=0 Prettier :CocCommand prettier.formatFile

" Sync NERDTree with open file
function! SyncTree()
  if &modifiable && IsNERDTreeOpen() && strlen(expand('%')) > 0 && !&diff
    NERDTreeFind
    wincmd p
  endif
endfunction

" Final mappings for NERDCommenter
nnoremap <Esc>tC :call NERDComment(0, "toggle")<CR>
vnoremap <Esc>tC :call nerdcommenter#Comment(0, "toggle")<CR>
nnoremap <D-/> :call NERDComment(0, "toggle")<CR>
vnoremap <D-/> :call nerdcommenter#Comment(0, "toggle")<CR>

inoremap <silent><expr> <Tab> pumvisible() ? "\<C-y>" : "\<Tab>"

" Map Shift-Tab to navigate backward in the popup menu
inoremap <silent><expr> <S-Tab> pumvisible() ? "\<C-p>" : "\<S-Tab>"

" Map Enter to confirm selection in the popup menu or insert a newline otherwise
inoremap <silent><expr> <CR> pumvisible() ? coc#_select_confirm() : "\<CR>"

" Ensure the completion popup behaves as expected
set completeopt=menuone,noinsert,noselect
set shortmess+=c
