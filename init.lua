-- Set <leader>
vim.g.mapleader = ","

-- Plugin manager (Lazy.nvim)
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git", "clone", "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git", lazypath
  })
end
vim.opt.rtp:prepend(lazypath)

require("lazy").setup({
  { "neoclide/coc.nvim", branch = "release" },
  "preservim/nerdtree",
  "Xuyuanp/nerdtree-git-plugin",
  "tiagofumo/vim-nerdtree-syntax-highlight",
  "ryanoasis/vim-devicons",
  "airblade/vim-gitgutter",
  "ctrlpvim/ctrlp.vim",
  "preservim/nerdcommenter",
  "christoomey/vim-tmux-navigator",
  "morhetz/gruvbox",
  "vim-airline/vim-airline",
  "vim-airline/vim-airline-themes",
  "HerringtonDarkholme/yats.vim",
  "maxmellon/vim-jsx-pretty",
  "projekt0n/github-nvim-theme",
  "dense-analysis/ale",
  "junegunn/fzf",
  "junegunn/fzf.vim",
  "github/copilot.vim",
  event = "InsertEnter",
})

-- UI & Appearance
vim.cmd("colorscheme gruvbox")
vim.o.background = "dark"
vim.o.number = true
vim.o.mouse = "a"
vim.o.ignorecase = true
vim.o.hlsearch = true
vim.o.backspace = "indent,eol,start"
vim.o.guifont = "DejaVu Sans:h12"
vim.o.foldmethod = "indent"
vim.o.smarttab = true
vim.o.cindent = true
vim.o.tabstop = 4
vim.o.shiftwidth = 4
vim.o.expandtab = true
vim.o.laststatus = 2
vim.o.signcolumn = "yes"
vim.o.hidden = true
vim.o.nobackup = true
vim.o.nowritebackup = true
vim.o.cmdheight = 2
vim.o.updatetime = 300
vim.o.shortmess = vim.o.shortmess .. "c"
vim.o.statusline = vim.o.statusline .. "%F"

-- ALE Configuration
vim.g.ale_linters_explicit = 1
vim.g.ale_fix_on_save = 0
vim.g.ale_sign_error = "E"
vim.g.ale_sign_warning = "W"
vim.g.ale_virtualtext_cursor = 1
vim.g.ale_virtualtext_prefix = ">> "
vim.g.ale_linters = {
  c = { "gcc", "clang" },
  cpp = { "g++", "clang++" },
  cs = { "omnisharp" },
  python = { "pylint" },
  html = { "tidy" },
  css = { "stylelint" },
  javascript = { "eslint" },
  java = { "javac" },
}
vim.g.ale_fixers = {}
vim.g.ale_completion_enabled = 1
vim.g.ale_lint_on_text_changed = "always"
vim.g.ale_lint_on_insert_leave = 1
vim.g.ale_lint_on_save = 1
vim.g.ale_lint_on_enter = 1
vim.g.ale_open_list = 1
vim.g.ale_keep_list_window_open = 0

-- Coc Configuration
vim.g.coc_global_extensions = {
  "coc-snippets",
  "coc-pairs",
  "coc-tsserver",
  "coc-eslint",
  "coc-json",
  "coc-html",
  "coc-clangd",
  "coc-csharp",
  "coc-java",
  "coc-pyright"
}

-- Keymaps
local keymap = vim.keymap.set
keymap("n", "<leader>n", ":NERDTreeFocus<CR>")
keymap("n", "<C-n>", ":NERDTreeToggle<CR>")
keymap("v", "++", "<Plug>NERDCommenterToggle", { silent = true })
keymap("n", "++", "<Plug>NERDCommenterToggle", { silent = true })
keymap("n", "gb", ":ls<CR>:b<Space>")
keymap("n", "ge", "yiw:%s/<C-r>0//g<Left><Left>")
keymap("n", "=", "<C-w>>")
keymap({ "n", "v" }, "<leader>y", '"+y')
keymap({ "n", "v" }, "<leader>p", '"+p')
keymap("n", "<leader>r", "@:")
keymap("n", "-", "<C-w><")
keymap("t", "<Esc>", "<C-\\><C-n>")
keymap("i", "<C-BS>", "<C-w>")

-- Resize
keymap("n", "<Leader>w+", ":vertical resize +5<CR>")
keymap("n", "<Leader>w-", ":vertical resize -5<CR>")
keymap("n", "<Leader>t", ":tabs<CR>")

-- Auto format
vim.cmd([[command! -nargs=0 Format :call CocAction('format')]])

-- Coc hover docs
vim.cmd([[
  function! ShowDocumentation()
    if index(['vim', 'help'], &filetype) >= 0
      execute 'h ' . expand('<cword>')
    else
      call CocAction('doHover')
    endif
  endfunction
]])

keymap("n", "K", ":call ShowDocumentation()<CR>", { silent = true })
keymap("n", "[g", "<Plug>(coc-diagnostic-prev)", { silent = true })
keymap("n", "]g", "<Plug>(coc-diagnostic-next)", { silent = true })
keymap("n", "<F2>", "<Plug>(coc-rename)")
keymap("x", "<leader>f", "<Plug>(coc-format-selected)")
keymap("n", "<leader>f", "<Plug>(coc-format-selected)")
keymap("n", "<leader>a", "<Plug>(coc-codeaction-selected)")
keymap("n", "<leader>ac", "<Plug>(coc-codeaction)")
keymap("n", "<C-d>", "<Plug>(coc-range-select)")
keymap("x", "<C-d>", "<Plug>(coc-range-select)")
keymap("i", "<C-Space>", "coc#refresh()", { expr = true, silent = true })

-- CursorHold highlight
vim.cmd([[autocmd CursorHold * silent call CocActionAsync('highlight')]])

-- Signature help
vim.cmd([[
augroup CocGroup
  autocmd!
  autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
  autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
augroup end
]])

-- Language-specific indentation
vim.cmd([[
  autocmd FileType c,cpp,cs,nasm,java,python setlocal tabstop=4 shiftwidth=4 expandtab
  autocmd FileType html setlocal tabstop=2 shiftwidth=2 expandtab
]])

-- Smart j/k
keymap("n", "j", "(v:count == 0 ? 'gj' : 'j')", { expr = true, silent = true })
keymap("n", "k", "(v:count == 0 ? 'gk' : 'k')", { expr = true, silent = true })

-- Delete-safe keymaps
keymap("n", "x", '"_x')
keymap("n", "d", '"_d')
keymap("n", "D", '"_D')
keymap("v", "d", '"_d')
keymap("n", "<leader>d", '""d')
keymap("n", "<leader>D", '""D')
keymap("v", "<leader>d", '""d')

-- NERDTree Config
vim.g.NERDTreeIgnore = { "^node_modules$" }
vim.g.NERDTreeGitStatusWithFlags = 1

-- Airline
vim.g.airline_theme = "gruvbox"

