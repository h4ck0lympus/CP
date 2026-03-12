(function () {
  const form = document.querySelector('form[method="post"]');
  if (!form) return;
  const fileInput = form.querySelector('input[type="file"]');
  const langSelect = form.querySelector('select[name="lang"]');
  if (!fileInput || !langSelect) return;

  const ta = document.createElement("textarea");
  ta.placeholder = "Paste your code here...";
  ta.style.cssText =
    "width:100%;min-height:300px;font-family:monospace;font-size:13px;padding:8px;box-sizing:border-box;tab-size:4;margin:8px 0;";
  ta.spellcheck = false;

  const btn = document.createElement("button");
  btn.type = "button";
  btn.textContent = "Submit Pasted Code";
  btn.style.cssText = "padding:6px 16px;margin-bottom:10px;cursor:pointer;";

  form.parentNode.insertBefore(btn, form);
  form.parentNode.insertBefore(ta, btn);

  function guessLang(code) {
    if (/^#include\b/m.test(code) || /\busing\s+namespace\b/.test(code)) return "C++";
    if (/\bpublic\s+static\s+void\s+main\b/.test(code)) return "Java";
    if (/^(import|from)\s+/m.test(code) || /\bdef\s+\w+\s*\(/.test(code)) return "Python3";
    if (/\bfn\s+main\b/.test(code)) return "Rust";
    return null;
  }

  function setLang(name) {
    if (!name) return;
    for (const opt of langSelect.options) {
      if (opt.text === name || opt.value === name) {
        langSelect.value = opt.value;
        return true;
      }
    }
    return false;
  }

  ta.addEventListener("input", function () {
    const lang = guessLang(this.value);
    if (lang) setLang(lang);
  });

  ta.addEventListener("keydown", function (e) {
    if (e.key === "Tab") {
      e.preventDefault();
      const s = this.selectionStart;
      this.value = this.value.slice(0, s) + "    " + this.value.slice(this.selectionEnd);
      this.selectionStart = this.selectionEnd = s + 4;
    }
  });

  btn.addEventListener("click", function () {
    if (!ta.value.trim()) return alert("Paste some code first.");
    if (langSelect.value === "?" || langSelect.value === "") {
      return alert("Please select a language.");
    }
    const dt = new DataTransfer();
    dt.items.add(new File([ta.value], "sol.cpp", { type: "text/plain" }));
    fileInput.files = dt.files;
    form.submit();
  });
})();
